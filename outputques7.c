//why does sizeof('a') return 4 instead of 1 in C?
#include <stdio.h>
int main() {
    printf("%d\n", sizeof('a'));   
    return 0;
}
// In C, 'a' is of type int, not char.

// So sizeof('a') == sizeof(int) → usually 4 on most systems.

// That’s why it doesn’t print 1.

//extra points
// (char)'a' → char → sizeof((char)'a') is 1.

// "a" → string literal of type char[2] ('a' + '\0') → sizeof("a") is 2.

// In C++, 'a' is type char, so sizeof('a') is 1 there.
