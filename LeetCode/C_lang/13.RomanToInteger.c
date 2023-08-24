#include "problems.h"
int romanToInt(char* s) {
    int sum = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'I' && s[i+1] == 'V') {
            sum += 4;
            i += 2;
        } else if (s[i] == 'I' && s[i+1] == 'X') {
            sum += 9;
            i += 2;
        } else if (s[i] == 'X' && s[i+1] == 'L') {
            sum += 40;
            i += 2;
        } else if (s[i] == 'X' && s[i+1] == 'C') {
            sum += 90;
            i += 2;
        } else if (s[i] == 'C' && s[i+1] == 'D') {
            sum += 400;
            i += 2;
        } else if (s[i] == 'C' && s[i+1] == 'M') {
            sum += 900;
            i += 2;
        } else {
            switch (s[i]) {
                case 'I':
                    sum += 1;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    sum += 10;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    sum += 100;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
                default:
                    // Handle invalid input characters
                    printf("Invalid input character: %c\n", s[i]);
                    return 0;
            }
            i++;
        }
    }
    return sum;
}