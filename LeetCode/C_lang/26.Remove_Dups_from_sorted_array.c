#include "problems.h"

#define TABLE_SIZE 100
#define DEFAULT (unsigned int)0xAA7AAAAAAAAA
int table[TABLE_SIZE] = {0};
unsigned int hash(int value)
{
    unsigned int address = (unsigned int)value % (unsigned int)TABLE_SIZE;
    return (address);
}
void init_table(void)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = DEFAULT;
    }
}
bool insert(int value)
{
    unsigned int address = hash(value);
    if (table[address] == DEFAULT)
    {
        table[address] = value;
        return (true);
    }
    return (false);
}

int removeDuplicates(int* nums, int numsSize)
{
    init_table();
    int *newarray = malloc(numsSize * sizeof(int));
    if (newarray == NULL)
    {
        return (1);
    }
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (insert(nums[i]) == true)
        {
            newarray[j] = nums[i];
            j++;
        }
    }
    memcpy(nums, newarray, j *sizeof(int));
    free(newarray);
    return (j);
}
/*int main(void)
{
    int nums[] = {-3,-1,-1,0,0,0,0,0,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = removeDuplicates(nums, numsSize);
    for (int i = 0; i < k; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\nk is %d\n",k);
    // int value = -3;
    // unsigned int address = abs(value % TABLE_SIZE);
    // printf("%d\n", address);
}*/