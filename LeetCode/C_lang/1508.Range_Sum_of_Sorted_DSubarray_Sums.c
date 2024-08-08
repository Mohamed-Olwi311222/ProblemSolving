#include "problems.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int rangeSum(int* nums, int numsSize, int n, int left, int right)
{
    int totalSubarrays = n * (n + 1) / 2;
    int sum_subarray[totalSubarrays];
    int sub_idx = 0;
    int modulo = pow(10, 9) + 7;
    long long curr_sum = 0;

    // Calculate all subarray sums
    for (int i = 0; i < numsSize; i++)
    {
        curr_sum = 0;
        for (int j = i; j < numsSize; j++)
        {
            curr_sum += nums[j];
            sum_subarray[sub_idx++] = curr_sum;
        }
    }

    // Sort subarray sums in non-decreasing order
    qsort(sum_subarray, totalSubarrays, sizeof(int), compare);

    // Calculate the sum from index left to right
    curr_sum = 0;
    for (int i = left - 1; i < right; i++)
    {
        curr_sum = (curr_sum + sum_subarray[i]) % modulo;
    }

    return (int)curr_sum;
}

