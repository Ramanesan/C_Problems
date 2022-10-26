#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

void removeDups(int* in, int size){
    int i,j,james;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if (in[i] == in[j]){
                in[j] = 0; 
            }
            else{
                in[j] = in[j];
            }
        }
    }
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
        if (in[i] == 0){
            int temp = in[i];
            in[i] = in[j];
            in[j] = temp;          
        }
        else{
            in[i] = in[i];
        }
    }
    } 
}

int main () {
    int A[] = {1,2,2,2,3,3,4,2,4,5,6,6,8,8,1,2,7,7};
    int size = sizeof(A)/sizeof(A[0]);
    removeDups(A,size);
    int loop;

   for(loop = 0; loop < size; loop++)
      printf("%d ", A[loop]);
 
    
    return 0;
}