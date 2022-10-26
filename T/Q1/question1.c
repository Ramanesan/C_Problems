#include<stdio.h>
#include <string.h>

int highfives (char hall[]) {
	int i = 0; int j =0;
	int len = strlen(hall);
	int fives = 0;
	for (i=0;i<len;i++){
		for(j=(i+1);j<len;j++){
			if((*(hall+i) == '>') && (*(hall+j) == '<')){
				fives += 1;
			}
		
		}

	}
	return fives;	
}

int main () {
	char hall1[] = ">><<";
	char hall2[] = ">-<<->----<><>>-";
	char hall3[] = ">-<->--<<>><->-<-->-<--->-<>->>->>-<<<->";
	printf("Hall 1 should have 4 high fives.  You got %d\n", highfives(hall1));
	printf("Hall 2 should have 7 high fives.  You got %d\n", highfives(hall2));
	printf("Hall 3 should have 63 high fives.  You got %d\n", highfives(hall3));
}