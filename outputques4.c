#include<stdio.h>
int main(){
    int x;
    x=(1,2,3);
    printf("%d", x);
}

//Hint:The comma operator evaluates from left to right, but the last value is stored