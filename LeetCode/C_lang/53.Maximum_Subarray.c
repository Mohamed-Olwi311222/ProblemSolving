#include "problems.h"

#define DEBUG (printf("i = %i, start = %i, end = %i\n", i, start, end))
#define SUM (printf("Sum = %i\n",sum))
int sumofarray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        SUM;
        sum += arr[i];
    }
    return (sum);
}
int subarrayfun(int *nums,int *subarray,int start,int sub_len)
{
    int sum = 0;
    *subarray = malloc(sizeof(int) * (sub_len));
    if (subarray == NULL)
        return (0);
    memcpy(*subarray,&nums[start], sub_len * sizeof(int));
    sum = sumofarray(subarray, sub_len);
    free(subarray);
    return (sum);
}
int maxSubArray(int* nums, int numsSize){
int i = 0, start = 0, end = 0, sum = 0, sub_len;
int *subarray;
if (numsSize == 1)
{
    return (nums[0]);
}

//nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//          0   1   2  3  4  5  6,  7,  8
//numsSize = 9
    while (i < numsSize)
    {
        if (nums[i] > nums[start])
        {
            start = i;
        }
        if (nums[start] < abs(nums[i]) )
        {
            end = i;
        }
        i++;
        DEBUG;
    }
    sub_len = abs(end - start);
    sum = subarrayfun(nums,subarray, start,sub_len);
    return (sum);
}
/*int main(void)
{
    int nums[] = {5,4,-1,7,8};
    // int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    // int nums[] = {0};
    // int nums[] = {1};
    int *ptr = nums;
    int size = sizeof(nums) / sizeof(nums[0]);
    int sum = maxSubArray(ptr, size);
    printf("\n%i\n", sum);
    return (0);
}*/