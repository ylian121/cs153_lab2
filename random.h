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


