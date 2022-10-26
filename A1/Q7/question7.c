#include <stdio.h>
#include <assert.h>
#include <math.h>


float convertor(float x){

}

void mileage (void){
    float fuel = 0;
    float Tfuel = 0;
    float distance  = 0;
    float Tdistance = 0;
    char response = 'y';
    while ( response == 'y'){
        printf("Please Enter amount of fuel used: \n");
        scanf("%f",&fuel);
        Tfuel += fuel;
        printf("Please Enter amount of distance travelled: \n");
        scanf("%f",&distance);
        Tdistance += distance;
        printf("Is there more information to be added ? Please enter y for yes and n for no \n");
        scanf(" %c", &response);
    }
    
    float gasmileage =  Tdistance/ Tfuel;
    printf( "Your Gasmileage is %.4f", gasmileage);
    
    
}

int main (void) {
	mileage();
    return 0;
}

