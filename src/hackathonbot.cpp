//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"
#include "cmath"

HackathonBot::HackathonBot(){
    recents = std::vector<float>();
    recents.reserve(3);
    recents.push_back(100);  
    action = Action();
    windows = 0;
    cycles = 0;
    origPrice = 100;
};

void HackathonBot::takeAction(float price){

    // Keeping track of price-change dependent counts
    if(recents.back() < price){
        if(windows < 0){
            windows = 0;
        }
        windows++;
    }
    else if(recents.back() > price){
        if(windows > 0){
            windows = 0;
        }
        windows--;
    }
    else{
        windows = 0;
    }

    if(abs(getPercentageDiff(recents.back(), price)) <= 0.05){
        cycles++;
    }

    // If currently holding a stock...
    if(action.getHold()){
        if(price > origPrice && getPercentageDiff(price, origPrice) >= 0.89){
            action.sell(price);
        }
        else if(price < origPrice && getPercentageDiff(price, origPrice) <= -0.62){
            action.sell(price);
        }
        else if(windows >= 52 || windows <= -47 || cycles >= 10){
            action.sell(price);
        }
        else if(recents.size() >= 3){
            if(getPercentageDiff(recents[0], recents[1]) >= 0.2 
                    && getPercentageDiff(recents[1], recents[2]) <= -0.15 
                    && getPercentageDiff(recents[2], price) >= 0.3
                    && getPercentageDiff(origPrice, price) >= 0.5){
                action.sell(price);
            }
            else if(getPercentageDiff(recents[0], recents[1]) <= -0.15 
                    && getPercentageDiff(recents[1], recents[2]) >= 0.15 
                    && getPercentageDiff(recents[2], price) <= -.25
                    && getPercentageDiff(origPrice, price) <= -0.45){
                action.sell(price);
            }
        }
    }
    // If not currently not holding a stock...
    else{
        if(price < 52 || windows <= -5){
            action.buy(price);
            origPrice = price;
        }
    }

    // populating recent prices vector
    if(recents.size() >= 3){
        recents.erase(recents.begin());
    }
    recents.push_back(price);

}

double HackathonBot::getBalance(){
    return action.getBalance();
}

bool HackathonBot::isHolding(){
    return action.getHold();
}

float HackathonBot::getPercentageDiff(float a, float b){
    return (a - b) / b;
}