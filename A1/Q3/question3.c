#include <stdio.h>
#include <assert.h>
#include <math.h>

int multiples (int x, int y, int N){
    int i = 0;
    int total = 0;
    for( i=1 ; i <= N ; i++){
        if ((i % x) == 0){
            total += i;
        } else if ((i%y) == 0){
            total += i;
        }
    }
    return total;
}


int main () {
    printf("the sum is %d", multiples(4,10,20));
    printf("the sum is %d", multiples(32,14,10));
    printf("the sum is %d", multiples(11,15,20));
    return 0;
}

