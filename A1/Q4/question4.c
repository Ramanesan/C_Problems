#include <stdio.h>
#include <assert.h>
#include <math.h>

float compoundInterest (float p, int a, int n){
    float power = pow((1+p), n );
    float total = a*power;
    return total;
}

int main () {
    printf("The future value is %f", compoundInterest(0.06,800,2));
    return 0;
}

