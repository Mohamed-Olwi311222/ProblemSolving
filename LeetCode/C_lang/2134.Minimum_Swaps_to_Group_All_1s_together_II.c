#include "problems.h"
/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element to be adjacent.
Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

Example 1:
Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.

Example 2:
Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.

Example 3:
Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
 */
int minSwaps(int* nums, int numsSize) {
    int total_ones = 0;
    int zero_count = 0;
    int min_zero = 0;
    int start = 0;
    int end = 0;
    int *circular_arr = NULL;

    //count the total number of ones
    for (int i = 0; i < numsSize; i++)
    {
        total_ones += nums[i];
    }
    if (total_ones == 0 || total_ones == numsSize)
    {
        return (0);
    }
    
    circular_arr = malloc(sizeof(int) * numsSize * 2);
    if (!circular_arr)
    {
        return(-1);
    }

    // fill the circular array and 
    for (int i = 0; i < numsSize; i++)
    {
        circular_arr[i] = nums[i];
        circular_arr[i + numsSize] = nums[i];
    }

    // Initialize zero count for the first window
    for (end = 0; end < total_ones; end++)
    {
        if (circular_arr[end] == 0)
        {
            zero_count++;
        }
    }
    min_zero = zero_count;

    // Slide the window
    for (end = total_ones; end < numsSize * 2; end++)
    {
        if (end - start > total_ones)
        {
            start++;
        }
        if (circular_arr[end] == 0)
        {
            zero_count++;
        }
        if (circular_arr[start] == 0)
        {
            zero_count--;
        }
        if (zero_count < min_zero)
        {
            min_zero = zero_count;
        }
    }
    free(circular_arr); //free the temporary circular array
    return (min_zero);
}
