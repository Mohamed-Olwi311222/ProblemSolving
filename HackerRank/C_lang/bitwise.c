#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int i = 1, a = 0, b = 0, and = 0, or = 0, xor = 0;

    for (; i <= n; i++)
    {
        a = i;
        for (int j = i + 1; j <= n; j++)
        {
            b = j;
            if ((a | b) > or && (a | b) < k)
            {
                or = a | b;
            }
            if ((a & b) > and && (a & b) < k)
            {
                and = a & b;
            }
            if ((a ^ b) > xor && (a ^ b) < k )
            {
                xor = a ^ b;
            }
        }
        
    }
    printf("%d\n", and);
    printf("%d\n", or);
    printf("%d\n", xor);
    
    
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

