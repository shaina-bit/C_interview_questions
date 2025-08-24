//swap two numbers without using a third variable.
#include <stdio.h>

int main() {
    int a = 5, b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);

    // Method 1: Arithmetic (addition & subtraction)
    a = a + b;   // a = 15
    b = a - b;   // b = 5
    a = a - b;   // a = 10

    printf("After swap (Arithmetic): a = %d, b = %d\n", a, b);

    // Reset values
    a = 5; b = 10;
    //xor: bit is 1 if bits are different, else 0.
    // Method 2: Bitwise XOR
    a = a ^ b;   // a = 5 ^ 10
    b = a ^ b;   // b = (5 ^ 10) ^ 10 = 5
    a = a ^ b;   // a = (5 ^ 10) ^ 5 = 10

    printf("After swap (XOR): a = %d, b = %d\n", a, b);

    return 0;
}
