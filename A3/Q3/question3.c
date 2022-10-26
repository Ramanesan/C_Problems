#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);


int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)){
int exams = 0; int count = 0; int h = 0; int j =0; int k =0; bool stop = false;
int *sub_array = (int*)malloc(size*sizeof(int));
if (sub_array == NULL){
    return -1;
}
for(int h=0;h_gaps[h]>=1;h++){
    if(h_gaps[h] == 1){
        stop = true;
    }
    if(h_gaps[h] <= (size/2)){
        for (j=0;j<=h_gaps[h];j++){
            count = 0;
            for(k=j;k<size;k+=(h_gaps[h]+1)){
                 *(sub_array + count) = *(array+k);
                count += 1;
            }
            exams += (*subsort)(sub_array,count);
            count = 0;
            for(k=j;k<size;k+=(h_gaps[h]+1)){
                *(array+k) = *(sub_array + count);
                count += 1;
            } 
                           
                
            }
        } 
    if(stop == true){
        break;
    }       
    }
free(sub_array);
exams += (*subsort)(array,size);
return exams;
}



int main () {
    // int array[] =  {44, 79, 8, 53, 93, 21, 70, 79, 82, 49, 25, 2, 62, 26, 29, 54, 89, 57, 74, 39};// Size is 20, so first value of H taken to be 10
    int array[] =  {135, 529, 81, 54, 46, 605, 47, 793, 278, 323, 306, 430, 973, 286, 712, 962, 461, 81, 57,325, 711, 995, 833, 222, 284, 293, 153, 224, 126, 643, 425, 400, 420, 309, 831, 6, 496, 347, 185, 583};
    int h_gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    int size = sizeof(array)/sizeof(array[0]);
    printf("%d",shellsort (array, size, h_gaps, bubblesort));
    // for (int i=0;i<size;i++) {
    //     printf("%d\t",array[i]);
    // }
    return 0;
}
