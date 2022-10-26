#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int bubblesort(int* x, int size){
    int i = 0;
    int j = 0;
    for(i=0;i<size;i++){
        for(j=0;j<(size-1);j++){
            if (x[j] > x[j+1]){
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }

    }
    
}

double mean(int* x, int size){
     float sum = 0;
     int i = 0;
     float total = 0;
     if (size == 0){
        total = 0;
     }
     else{
         for(i=0;i<size;i++){
         sum += x[i];
     }
     total = (sum/size);
     }
     
     return total;
}

double median(int* x, int size){
    int i = 0;
    float final = 0;
    bubblesort(x,size);
    if(size == 0){
        final = 0;
    }
    else if (size%2 == 0){
        int mid = size/2;
        final += (x[mid]+x[mid-1])/2.0; 
    }
    else{
        int mid = (size+1)/2;
        final += x[(mid-1)];

    }     
    return final;
}

int mode(int* x, int size){
    int finalval = 0 ;
    int finalcount = 0 ;
    int i = 0;
    int j = 0;
    for(i=0;i<size;++i){
        int count = 0;
        for(j=0;j<size;++j){
            if(x[j] == x[i])
            ++count;
            
        }
        if(count > finalcount){
            finalcount = count;
            finalval = x[i];
        }
    
    }return finalval;
}





int main () {
    int x[] = {0};
    printf("mean is %f \n",mean( x , 1));
    printf("median is %f \n",median( x , 1));
    printf("mode is %d",mode( x , 1));
    return 0;

}
