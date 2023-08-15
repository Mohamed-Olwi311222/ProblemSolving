#include <stdio.h>
#include <stdlib.h>
int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int majorityElement(int* nums, int numsSize){
 qsort(nums, numsSize, sizeof(int), compare_int);
 return (nums[numsSize / 2]);
}