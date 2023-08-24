#include "problems.h"

int mySqrt(int x){
    if (x == 0 || x == 1)
        return (x);
    int right = (x / 2) + 1, left = 0;
    long mid = left + (right - left) / 2, product = mid * mid;
  
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        product = mid * mid;
        if (product == x)
            return (int)(mid);
        else if (product > x)
            right =(int) mid - 1;
        else
            left = (int)mid + 1;

    }

    return (left - 1);
        
}