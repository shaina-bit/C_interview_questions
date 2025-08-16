//question 1: print hello world without using ;
//method 1
#include<stdio.h>
int main(){
    if(puts("Hello World")){}
}
// puts prints a string and automatically adds a newline.
// It also returns a non-negative value, so the if works.

//method 2
#include<stdio.h>
int main() {
    return !printf("Hello World");
}
// print "Hello World", then ! negates the return value, giving 0, so the program exits successfully.
//method 3
#include <stdio.h>
int main() {
    switch(printf("Hello World")) {}
}
//printf executes first, then switch runs with the return value.

//method 4
#include <stdio.h>
int main() {
    while(!printf("Hello World")) {}
}
//since printf prints and returns a non-zero value, the loop runs only once.
//method 5- i like this the best!
#include <stdio.h>
int main() {
    if (printf("Hello World"))
    {}
}
//printf returns the number of characters printed, which is non-zero, so the if condition works without needing ;.

//on windows use: ./a.exe to get output. 