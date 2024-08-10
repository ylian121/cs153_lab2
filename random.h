#include <cstdlib> 
#include <iostream> 
#include <random>
using namespace std; 

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


