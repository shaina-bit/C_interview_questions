// Given an integer, turn off the rightmost set bit.
#include <stdio.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n = 44;
    printf("Original: %d\n", n);
    printf("After turning off rightmost set bit: %d\n", turnOffRightmostSetBit(n));
    return 0;
}
//example: 
// n      = 101100 (44)
// n - 1  = 101011 (43)
// -------------------
// n & n-1 = 101000 (40)
