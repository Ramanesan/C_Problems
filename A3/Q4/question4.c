#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

void swap (int* num1, int* num2);

int insertionsort(int* x, int size, int (*compare)(int a, int b)){
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
            if (!(*compare)(x[j],current)){
                break;
            }
            else {
                swap(&x[j],&x[j+1]);
                j -= 1;         
            }          
        }
        }
        return (comps);
    } 

int ascending (int a, int b){
    return (b<a);
}
int descending (int a, int b){
    return (b>a);
}
void swap (int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main () {
    int x[]= {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int y = insertionsort(x, 14, descending);
    printf("%d",y);
      
    return 0;
}