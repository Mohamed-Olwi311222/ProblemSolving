#include "problems.h"
/*
A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

 

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/



#define TABLE_SIZE          1000
#define STR_MAX             6

typedef struct
{
    char value[STR_MAX]; /*to store string value*/
    int kth_distinct;   /*to store how many time a string appeared*/
} hash_map_t;

/*frequency map*/
hash_map_t map[TABLE_SIZE];
int distinctSize = 0; /*index of the last distinct items inserted*/

void insert_element(hash_map_t *map, const char* str)
{
    /*Compare first if exists increment its kth_distinct else insert it and put its
    value and kth_distinct = 1*/ 
    for (int i = 0; i < distinctSize; i++)
    {
        if (strcmp(map[i].value, str) == 0)
        {
            map[i].kth_distinct++;
            return;
        }
    }
    strcpy(map[distinctSize].value, str);
    map[distinctSize].kth_distinct = 1;
    distinctSize++;
}


char* kthDistinct(char** arr, int arrSize, int k)
{
    char *result = "";
    int count = 0;

    if (NULL == arr)
    {
        return (result);
    }
    /*init map to be zero*/
    memset(map, 0, sizeof(map));
    distinctSize = 0;

    for (int i = 0; i < arrSize; i++)
    {
        insert_element(map, arr[i]);
    }
    for (int i = 0; i < distinctSize; i++)
    {
        if (map[i].kth_distinct == 1)
        {
            count++; /*if number of the element appeared = k, its our ans*/
            if (count == k)
            {
                result = map[i].value;
                break;
            }
        }
    }
    return(result);
}
