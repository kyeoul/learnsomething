//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
    float getPercentageDiff(float a, float b);
private:
    double balance;
    bool holding;

    std::vector<float> recents;
    int windows;
    int cycles;
    float origPrice;
    Action action;
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
