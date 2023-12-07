#include "problems.h"
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    int right = numbersSize - 1;
    int left = 0;
    int sum = 0;

    *returnSize = 2;
    if (result == NULL)
    {
        return (NULL);
    }
    while (true)
    {
        sum = numbers[right] + numbers[left];
        if (sum == target)
        {
            result[0] = left + 1;
            result[1] = right + 1;
            break;
        }
        if (sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return (result);
}
