#include "problems.h"

int cmpfunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
bool containsDuplicate(int* nums, int numsSize){
    int i, j ;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1]) 
            return (true);
    }
    return (false);
}