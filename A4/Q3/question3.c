#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp);

int simpleParse(const char *exp){
int i = 0; int total = 0; bool sums = true; int product = 0; int len = 0 ; bool dig = false; bool blank = false; char op = '0'; long val = 0 ;
// char *startptr = &exp[i];
char *endptr = NULL;
len = strlen(exp);
for(i = 0; i < len ; i++) {
    dig = isdigit(exp[i]);
    blank = isspace(exp[i]);
    if (dig == true){
            val = strtol(&exp[i],&endptr,10);
            i = endptr - exp ; 
            // val = strtol(&exp[i], &endptr, 10);
            // assigns operand and performs operation on currect number in string
            if (op == '*'){
                product *= val;
            }
            if (op == '/'){
                product /= val;
            }
            if(op == '%'){
                product %= val;
            }
            if(op == '0' ){
                product = val;
            }  
    }

    //checks for next operand
    if((exp[i] == '*') || (exp[i] == '/') || (exp[i] == '%')){
        op = exp[i];
    }    


    //checks for addition or subtraction
    if((exp[i] == '+') || (exp[i] == '-')){
        if(sums == true){
            total += product;            
        }
        else if(sums == false){
            total -= product;    
        }
        if((exp[i] == '+')){
            sums = true;
        }
        else{
            sums = false;
        }
        op = '0';

    }
     
}

if(sums == true){
    total += product;
}
if(sums  == false){
    total -= product;
}

 
    return total;
}

//start pointer = end pointer 
//while it is a digit
// increment end pointer
// get the numer using strtol
//find operator (if statements)
//keep track of - or +, add or subtract the product


int main() {
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));
}