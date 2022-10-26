#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;

struct node *element(struct node *dll, int i) {
    int n = 0;
    while (n<i) {
        if(dll == NULL){
            return NULL;
        }
        dll = dll->next;
        n++;        
    }
    return (dll);
}

struct node *add(struct node *dll, int i, int value) {
    int n = 0;
    NODE *current = dll;
    NODE *val = malloc(sizeof(NODE));
    NODE *O_prev = element(dll,i-1);
    NODE *O_next = element(dll,i);

    if (i<0 || (element(dll,i) == NULL)){
        val->value = value;
        val->next = NULL;
        while (current->next){
            current = current -> next;
        }
        current -> next = val;      
    }

    else{
    val->value = value;
    O_prev->next = val;
    O_next->prev = val;
    val->next = O_next;
    val->prev = O_prev;
    }
   
    return dll;
}

struct node *delete(struct node *dll, int i){
    NODE *current = dll;
    NODE *val = malloc(sizeof(NODE));
    NODE *Oldp = element(dll,i-1);
    NODE *Oldn = element(dll,i+1);
    NODE *p = element(dll,i);

    if((dll->next == NULL)&&(dll->prev == NULL)){
        return NULL;
    }

    else if(i==0) {
        dll = dll->next;
        dll->prev = NULL;
    }

    else if ((element(dll,i) == NULL)){
        return dll;
    }


    else{
        Oldp->next = Oldn;
        Oldn->prev = Oldp;
    }
    return dll;

}



void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
     //Testing code! //
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    dll->next = NULL;
    dll->prev = NULL;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll); 
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll); 
    dll = delete(dll, 2);
    printLL(dll); 
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll); 
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    printLL(dll); 
}

/* //Expected Output: //

---
< This: 0x152f590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x152f590 - 1 - P : (nil) - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f590 - N : (nil) >
---

---
< This: 0x152f590 - 1 - P : (nil) - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f590 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : (nil) >
---

---
< This: 0x152f590 - 1 - P : (nil) - N : 0x152f5f0 >
< This: 0x152f5f0 - 2 - P : 0x152f590 - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f5f0 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : (nil) >
---

---
< This: 0x152f590 - 1 - P : (nil) - N : 0x152f5f0 >
< This: 0x152f5f0 - 2 - P : 0x152f590 - N : 0x152f610 >
< This: 0x152f610 - 7 - P : 0x152f5f0 - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f610 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : (nil) >
---

---
< This: 0x152f590 - 1 - P : (nil) - N : 0x152f5f0 >
< This: 0x152f5f0 - 2 - P : 0x152f590 - N : 0x152f610 >
< This: 0x152f610 - 7 - P : 0x152f5f0 - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f610 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : 0x152f630 >
< This: 0x152f630 - -1 - P : 0x152f5d0 - N : (nil) >
---

---
< This: 0x152f590 - 1 - P : (nil) - N : 0x152f5f0 >
< This: 0x152f5f0 - 2 - P : 0x152f590 - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f5f0 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : 0x152f630 >
< This: 0x152f630 - -1 - P : 0x152f5d0 - N : (nil) >
---

---
< This: 0x152f5f0 - 2 - P : (nil) - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f5f0 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : 0x152f630 >
< This: 0x152f630 - -1 - P : 0x152f5d0 - N : (nil) >
---

---
< This: 0x152f5f0 - 2 - P : (nil) - N : 0x152f5b0 >
< This: 0x152f5b0 - 3 - P : 0x152f5f0 - N : 0x152f5d0 >
< This: 0x152f5d0 - 4 - P : 0x152f5b0 - N : 0x152f630 >
< This: 0x152f630 - -1 - P : 0x152f5d0 - N : (nil) >
---

---
--- */
