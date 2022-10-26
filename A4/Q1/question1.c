#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

float fkgrade(char str[]);

int wordcount(char str[]){
    int words = 1; int i =0; int len = 0; bool result = 0; bool result2 = 0; bool result3=0; bool result4=0;
    len = strlen(str);
    if(len == 0){
        words = 0;
    }
    for(i=0;i<len;i++){
        result = isspace(str[i]);
        if (str[i] == '('){
            words += 1;
        }
        else if (result == true){
            words += 1;
            result2 = isalnum(str[i+1]);
            result3 = iscntrl(str[i+1]);
            
            if (result2 == false){
                words -= 1;
            }
            if (result3 == true){
                words -= 1;
            }
            
            
        }
        
    }
    return words;
}

int sencount(char str[]){
    int sens = 0; int i =0; int len = 0; bool result = 0; int words = 0;
    len = strlen(str);
    words = wordcount(str);
    for(i=0;i<len;i++){
        if ((str[i] == '!') || (str[i] == '?') || (str[i] == '.')){
            sens += 1;
        }
    }
    if ((words != 0) && (sens == 0)){
            sens = 1;
        }
    return sens;
}

int syll(char str[]){
    int syl = 0; int i =0; int len = 0; int j = 0;
    len = strlen(str);
    for(i=0;i<len;i++){
        if (str[i] == 'a' ||str[i] == 'e' || str[i] == 'i' ||str[i] == 'o' || str[i] == 'u'|| str[i] == 'A' ||str[i] == 'E' || str[i] == 'I' ||str[i] == 'O' ||str[i] == 'U'){
            j = i+1;
            if(str[j] != 'a' && str[j] != 'e' && str[j] !=  'i' && str[j] !=  'o'&& str[j] !=  'u'&&  str[j] != 'A' && str[j] != 'E' &&  str[j] !=  'I' && str[j] != 'O' &&str[j] != 'U'){
                syl += 1;
                j++;
            }
        }
        
    }
    return syl;
}

float fkgrade(char str[]){
    float grade = 0; float words = 0; float sent = 0; float syl = 0;
    words = wordcount(str);
    sent = sencount(str);
    syl = syll(str);
    if((sent == 0) || (words == 0)){
        grade = 0;
    }
    else{
        grade = (0.39*(words/sent)) + (11.8*(syl/words)) - 15.59;
    }
    
    return grade;

}


int main() {
    
    char plato[] = "He who is the real tyrant, whatever men may think, is the real slave, and is obliged to practise the greatest adulation and servility, and to be the flatterer of the vilest of mankind.  He has desires which he is utterly unable to satisfy, and has more wants than any one, and is truly poor, if you know how to inspect the whole soul of him: all his life long he is beset with fear and is full of convulsions and distractions, even as the State which he resembles: and surely the resemblance holds?";
     
    char aurelius[] = "Nothing pertains to human beings except what defines us as human.  No other things can be demanded of us.  They aren't proper to human nature, nor is it incomplete without them.  It follows that they are not our goal, or what helps us reach it -- the good.  If any of them were proper to us, it would be improper to disdain or resist it.  If the things themselves were good, it could hardly be good to give them up.  But in reality, the more we deny ourselves such things (and things like them) -- or are deprived of them involuntarily, even -- the better we become.";

    char descartes[] = "I suppose, accordingly, that all the things which I see are false (fictitious); I believe that none of those objects which my fallacious memory represents ever existed; I suppose that I possess no senses; I believe that body, figure, extension, motion, and place are merely fictions of my mind.  What is there, then, that can be esteemed true?  Perhaps this only, that there is absolutely nothing certain.";
    
    char empty[] = "    ";
    printf("word count is %d\n", wordcount(empty));
    printf("sentence count is %d\n", sencount(empty));
    printf("syllables count is %d\n", syll(empty));
    printf("grade count is %f\n", fkgrade(empty));

    
    
    printf("Plato...\n expected sentences = 2\nexpected words = 94\n  expected syllables = 135\n");
    float out = fkgrade(plato);
    printf("> Reading Level = %f\n", out);
    printf("Marcus Aurelius...\n  expected sentences = 7\n   expected words = 104\n    expected syllables = 151\n");
    out = fkgrade(aurelius);
    printf("> Reading Level = %f\n", out);
    printf("Rene Descartes...\n  expected sentences = 3\n   expected words = 67\n    expected syllables = 111\n");
    out = fkgrade(descartes);
    printf("> Reading Level = %f\n", out);
    out = fkgrade(empty);
    printf("> Reading Level = %f\n", out);
}