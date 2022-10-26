#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str){
    int i = 0 ;
    int len= strlen(str)-1;
    while(i<len){
        int temp= *(str+len);
        *(str+len)=*(str+i);
        *(str+i)=temp;
        i++;
        len--;
    }
}
        
int count(char* str){
    int i;
    int vowels = 0; 
    char string;
    int length = strlen(str);
    for (i=0;i<length;i++){
        string = *(str+i);
        if (string == 'a' ||string == 'e' || string == 'i' ||string == 'o' || string == 'u'|| string == 'A' ||string == 'E' || string == 'I' ||string == 'O' ||string == 'U'){
        vowels += 1;
        }
        else{
            vowels += 0;
        }
    }
    return vowels;
}

int main () {
    char s[] = "RaME";
    reverse(s);
    printf("%s\n",s);
    printf("%d \n",count(s));
   return 0;
}