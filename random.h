#include "param.h"
#include "types.h"
#include "defs.h"

//to generate a random number without using the rand() function
//built into c++
//doesn't work for some reason
//using LCG method from gpt

// Linear Congruential Generator (LCG) 
const unsigned long a = 1664525; // Multiplier
const unsigned long c = 1013904223; // Increment
const unsigned long m = 0xFFFFFFFF; // Modulus

unsigned long seed = 1; // Initial seed value

unsigned long lcg_rand() {
    seed = (a * seed + c) % m;
    return seed;
}

// Generate a random number within a specific range [min, max]
int random_in_range(int min, int max) {
    //added edge cases
    //maybe causing error if they are equal
    //divison by zero
    if(max == min){
        return min;
    } else if(max < min){
        int temp = max;
        max = min;
        min = temp;
    }
    return min + (lcg_rand() % (max - min + 1));
}




/*
#include <cstdlib>

#include "param.h"
#include "types.h"
#include "defs.h"

int
randomRange(int low, int high)
{
    //generate random number with
    //lower and upper bound
    return (rand() % (high - low + 1)) + low; 
}

*/
