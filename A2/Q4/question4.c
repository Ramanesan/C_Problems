#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size){
    int i = 0;
    int j = 0;
    int comps = 0;
    for(i=1;i<size;i++){
        j = i -1;
        int current = x[i];
        
        while(1){
            if (j<0){
                break;
            } 
            comps += 1;
            if (x[j]<=current){
                break;
            
              }
            else {
                int temp;
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;                
                j -= 1;
            }           
        }
        }
        return (comps);
    } 


int main () {
    int x[]= {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
   printf("examinations is %d",insertionsort(x,14));
    return 0;
}