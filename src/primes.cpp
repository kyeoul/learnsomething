#include "primes.h"
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

Primes::Primes() {};

// primes = [2]
//     for i in range(2, 1000):
//         factors = []
//         isPrime = True
//         for prime in primes:
//             if i % prime == 0:
//                 factors.append(prime)
//                 isPrime = False
//         if isPrime:
//             primes.append(i)


void Primes::calcPrimes(){

    vector<int> prime {2};
    vector<vector<int>> memo {};
    vector<int>::iterator ptr;
    memo.resize(1000);
    for(int i = 2; i < 1000; i++){
        bool isPrime = true;
        vector<int> factor {};
        ptr = prime.begin();
        while(ptr < prime.end() && *ptr <= sqrt(i)){
            int num = *ptr;
            if(i % num == 0){
                int memoindex = i / num;
                factor.reserve(memo[memoindex].size() + 1);
                factor.push_back(num);
                factor.insert(factor.end(), memo[memoindex].begin(), memo[memoindex].end());
                isPrime = false;
                break;
            }
            ptr++;
        }
        if(isPrime){
            prime.push_back(i);
            factor.push_back(i);
        }

        memo[i] = factor;
    }
}