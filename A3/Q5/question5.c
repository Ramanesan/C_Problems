#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int isEmpty (const long *start, const long *end){
    if(start == end){
        return 1;
    }
    else if ((start ==NULL)||(end == NULL)){
     return 1;
    }
    else{
        return 0;
    }

}
void push (long **start, long **end, long value){
    if(isEmpty(*start,*end)){
        *start = malloc(sizeof(long));
        if (*start == NULL){
            printf("Runtime Error");
            return;
        }
        *end = (*start + 1);
        **start = value;
    }
    else{
        int size = (*end - *start);
        *start = realloc(*start,(size+1)*sizeof(long));
        **(end) = value;
        *end += 1;
    }
    
}
long pop (long **start, long **end); // You don't have to implement this one.



// This testing code has been provided curteousy of ACME Inc.
//   "Our products are perfectly capable of catching road runners."

void printStack(long **start, long **end) {
    printf("Stack --> [ ");
    if (!isEmpty(*start, *end)) {
        for (int i = 0; *start + i < *end; i++) {
            printf("%ld ", (*start)[i]);
        }
    } 
    printf("]\n");
}

int main () {
    printf("Starting...\n");
    long *start = NULL;
    long *stop = NULL;
    printStack(&start, &stop);
    push(&start, &stop, 1L);
    printStack(&start, &stop);
    push(&start, &stop, 2L);
    printStack(&start, &stop);
    push(&start, &stop, 3L);
    printStack(&start, &stop);
    push(&start, &stop, 4L);
    printStack(&start, &stop);
    push(&start, &stop, 5L);
    printStack(&start, &stop);
    
    /* long out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop); */
    
/***Expected Output:****

Starting...
Stack --> [ ]
Stack --> [ 1 ]
Stack --> [ 1 2 ]
Stack --> [ 1 2 3 ]
Stack --> [ 1 2 3 4 ]
Stack --> [ 1 2 3 4 5 ]
popped 5
Stack --> [ 1 2 3 4 ]
popped 4
Stack --> [ 1 2 3 ]
popped 3
Stack --> [ 1 2 ]
popped 2
Stack --> [ 1 ]
popped 1
Stack --> [ ]
popped 0
Stack --> [ ]

**********************/
    
}