#include <stdio.h>
#include <assert.h>
#include <math.h>

int FactorialWhile (int n){
    int i = 1;
    int total = 1;
    while (i <= n){
        total *= i;
        i++;
    }
return total;
}

int FactorialDoWhile (int n){
    int i = 1;
    int total = 1;
    do{
        total *= i;
        i++;
    } while (i<= n);
    return total;
}

int main () {
    printf("%d",FactorialWhile(10));
    printf("\n");
    printf("%d",FactorialDoWhile(10));
    return 0;
}

