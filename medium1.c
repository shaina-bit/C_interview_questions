//Write a program to find the largest among three numbers without using logical operators.#include <stdio.h>
#include <stdio.h>
int main() {
    int a, b, c, largest;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    //finding the larger of a and b using ternary operator
    int temp = (a > b) ? a : b;

    // Now compare temp with c
    largest = (temp > c) ? temp : c;

    printf("The largest number is: %d\n", largest);

    return 0;
}
