#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

int LeapYearCheck (int n){
    if((n%4 == 0) && (n%100 != 0)) {
        return true;
        }
    else if ((n%4 == 0) && (n%100 == 0)){
        if(n%400 == 0){
            return true;
        }
        else {
            return false;
        }
    }
    else {
            return false;
        }
        
    
}
        


int main () {
    if((LeapYearCheck(2021)) == true) {
        printf("it is a leap year");
    }
    else{
        printf("it is not a leap year");
    }

    return 0;
}

