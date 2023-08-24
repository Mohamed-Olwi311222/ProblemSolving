#include "problems.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *array = (int *) malloc(sizeof(int) * 2);
    if (array == NULL)
        return (NULL);
    
    array[0] = 0;
    array[1] = 0;
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                array[0] = i;
                array[1] = j;
                return (array);
            }
        }
    }
    *returnSize = 0;
    return (NULL);
}