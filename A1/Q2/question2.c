#include <stdio.h>
#include <assert.h>
#include <math.h>

float onethird (int n){
    float total = 0;
   for (float i = 1; i<=n ; i++){
       total += (i*i); 
   }

   float final = 1.0*total/(pow(n,3));
   
   return final;
}

int main () {
    printf("final number %f ", onethird(9999));
    return 0;
}

