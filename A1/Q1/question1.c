#include <stdio.h>
#include <assert.h>
#include <math.h>

int minutes (int m, int h, int d){
    int min = m+h*60+d*24*60;
    
    return min;

}

int main () {
     printf("The total minutes %d", minutes(1,1,1) );
     printf("The total minutes %d", minutes(30,15,2) );
     
    return 0;
}

