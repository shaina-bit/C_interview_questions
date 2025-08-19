
#include<stdio.h>
int main() {
    int i = 5;
    printf("%d %d %d", i, i++, ++i);
}

//correct answer will be that it is an undefined behaviour- output may vary.
//answer 1- 7 5 6
//answer 2- 7 6 7
