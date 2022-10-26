#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size){
    int i = 0;
    int j = 0;
    int swaps = 0;
    for(i=0;i<size;i++){
        for(j=0;j<(size-1);j++){
            if (x[j] > x[j+1]){
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
                swaps += 1;
            }
        }

    }
    return swaps;
}

int main () {
    int x[]= {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    printf("swaps %d", bubblesort(x,14));
    return 0;
}