#include <stdio.h>
#include <stdbool.h>

int sumSequence(int *start, int *end);
bool compareSequences(int *start1, int *end1, int *start2, int *end2);
int maxRepeatedSequence(int *array, int arraysize, int **seq1, int **seq2, int *seqsize);

int sumSequence(int *start, int *end) { 
    int sum = 0; int i = 0;
    int size = (end - start) + 1;
    for(i=0;i<size;i++){
        sum += *(start + i);
    }
    return sum; 
}

bool compareSequences(int *start1, int *end1, int *start2, int *end2) {
    int size1 = (end1 - start1) + 1;
    int size2 = (end2 - start2) + 1;
    int i = 0; bool x = 0;
    if (size1 == size2){
        for (i=0;i<size1;i++){
            if(*(start1 + i) == *(start2 + i)){
                x= true;
            }
            else{
                x=false;
            }
        }
    
    }
    else{
        x= false;
    }    
    return x;
}


/* int maxRepeatedSequence(int *array, int arraysize, int **seq1, int **seq2, int *seqsize) {

        bool runfirst = false;
        int start1, start2, end1, end2; //One repeating subset
        int startmax1, startmax2, endmax1, endmax2 = -1;
        int starttemp1, starttemp2, endtemp1, endtemp2;
        bool stop = false;
        bool firstSub = true;

    
        // Finding Start of subarray    
        for (int i = 0; i < arraysize && !stop; i++) {

            // Finding End of First subarray
            for (int j = i+1; j < arraysize ; j ++) {

                if (array[i] == array[j]){ 
                    start1 = i;
                    start2 = j;
                    

                    for (int k = 0; k < (arraysize-j); k ++) {

                        if (array[i + k] == array [j + k]) {
                            end1 = i+k;
                            end2 = j+ k;
                        }
                    }

                  

                    if (firstSub) { 

                        startmax1 = start1;
                        startmax2 = start2;

                        endmax1 = end1;
                        endmax2 = end2 ;

                        firstSub = false;
                    } else {
                        stop = true;
                    }

                    i = end1 -1;
                    j = end2;
                    
                    break;
                    
                }
            }
    }

    end1 ++; 
    end2 ++;

    printf("MS - %d ME - %d   MS1 - %d ME1 - %d  -  OS - %d OE - %d    OS1 - %d OE1 -%d \n", startmax1, endmax1, startmax2, endmax2, start1, end1, start2, end2);


    int sum1 = sumSequence(&startmax1, &startmax2);
    int sum2 = sumSequence(&start1, &start2);
    int size = (startmax2 - startmax1);

    **seqsize = size;
    if (sum1 > sum2) {
        **seq1 = startmax1;
        return sum1;
    } else {
        **seq2 = startmax2;
        return sum2;
    } */
    int maxRepeatedSequence(int *array, int arraysize, int **seq1, int **seq2, int *seqsize){
    int i = 0; int j=0; int max = 0; int l = 0; int final = 0;
    int *start1 =0; int *end1=0; int *start2 = 0; int *end2 = 0; bool stop = false;
    for(i=0;i<arraysize && !stop;i++){
        for(j=i+1;j<arraysize && !stop;j++){
            if(*(array + i) == *(array + j)){
                for(l =1; l<(j-i); l++){
                    start1 = &array[i];
                    start2 = &array[j];
                    end1 = &array[i+l];
                    end2 = &array[j+l];
                    if(compareSequences(start1,end1,start2,end2)){
                        int final = sumSequence(start1, end1);
                        if(final > max){
                            *seq1 = start1;
                            *seq2 = start2; 
                            *seqsize = l + 1;
                            max = final;
                        }
                    }
                    else{
                        break;
                    }

                }
            }
        }
    }
    return max;
}

int main () {
    int array1[] = {1,2,3,4,5,3,4,6};
    int array2[] = {1,2,3,4,5,6,7,8,4,5,6,7,8,9,10};
    int *sequence1;
    int *sequence2;
    int size;
    int array3[] = {1,2,4,5,1,2,4,5};

    printf("Summing function test 1 : %d\n"
          , sumSequence( &(array1[2]) // start
                       , &(array1[5]) // end
                       )
          );
    printf("> Correct result was 15\n");
    
    printf("Comparison function test 1 : %d\n"
          , compareSequences( &(array1[2]) // start1
                            , &(array1[3]) // end1
                            , &(array1[5]) // start2
                            , &(array1[6]) // end2
                            )
          );
    printf("> Correct result was 1 (true)\n");
    
    printf("Comparison function test 2 : %d\n"
          , compareSequences( &(array1[2]) // start1
                            , &(array1[3]) // end1
                            , &(array1[6]) // start2
                            , &(array1[7]) // end2
                            )
          );
    printf("> Correct result was 0 (false)\n");
    
    printf("Comparison function test 3 : %d\n"
          , compareSequences( &(array1[2]) // start1
                            , &(array1[3]) // end1
                            , &(array1[5]) // start2
                            , &(array1[7]) // end2
                            )
          );
    printf("> Correct result was 0 (false)\n\n");
    
    int max = 0;

    printf("For Array 1: \n");
     max = maxRepeatedSequence(array1, 8, &sequence1, &sequence2, &size);
    printf("Expected: The subsequences start at index 2 and 5, and are 2 numbers long. The max sum is 7.\n");
    printf("Obtained: The subsequences start at index %ld and %ld, and are %d numbers long. The max sum is %d.\n", (sequence1-array1), (sequence2-array1), size, max);

    printf("\nFor Array 2: \n");
    max = maxRepeatedSequence(array2, 15, &sequence1, &sequence2, &size);
    printf("Expected: The subsequences start at index 3 and 8, and are 5 numbers long. The max sum is 30.\n");
    printf("Obtained: The subsequences start at index %ld and %ld, and are %d numbers long.  The max sum is %d.\n", (sequence1-array2), (sequence2-array2), size, max);
    
}
