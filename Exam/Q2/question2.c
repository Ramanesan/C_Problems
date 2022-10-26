#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cellTest (char *board, int w, int h, int x, int y) {
	int index = 0; char initial = ' '; int value = 0; char *temp;
	int index2 = 0; char initial2 = ' '; int value2 = 0;
	int index3 = 0; char initial3 = ' '; int value3 = 0;
	int index4 = 0; char initial4 = ' '; int value4 = 0;
	int index5 = 0; char initial5 = ' '; int value5 = 0;
	int index6 = 0; char initial6 = ' '; int value6 = 0;
	int index7 = 0; char initial7 = ' '; int value7 = 0;
	int index8 = 0; char initial8 = ' '; int value8 = 0;
	int index9 = 0; char initial9 = ' '; int value9 = 0;
	int sum1 = 0; int sum2=0; char alive = '1';

	index = (y*w) + x;
	initial = board[index];
	value = board[index] - '0';

	index2 = ((y+1)*w) + x;
    if((y+1)>6){value2 = 0;}
    else{
    initial2 = board[index2];
	value2 = board[index2] - '0';
    }	

	index3 = ((y-1)*w) + x;
    if((y-1)<0){value3 = 0;}
    else{
	initial3 = board[index3];
	value3 = board[index3] - '0';
    }

	if((x+1)>8){value4 = 0;}
    else{
    index4 = (y*w) + (x+1);
	initial4 = board[index4];
	value4 = board[index4] - '0';
    }

	index5 = (y*w) + (x-1);
    if((x-1)<0){value5 = 0;}
	else{
    initial5 = board[index5];
	value5 = board[index5] - '0';
    }

    if(((x+1)>8)||((y+1)>6)){value6 = 0;}
    else{
	index6 = ((y+1)*w) + (x+1);
	initial6 = board[index6];
	value6 = board[index6] - '0';
    }

    if(((x+1)>8)||((y-1)<0)){value7 = 0;}
    else{
	index7 = ((y-1)*w) + (x+1);
	initial7 = board[index7];
	value7 = board[index7] - '0';
    }

    if(((x-1)<0)||((y+1)>6)){value8 = 0;}
    else{
	index8 = ((y+1)*w) + (x-1);
	initial8 = board[index8];
	value8 = board[index8] - '0';
    }

    if(((x-1)<0)||((y-1)<0)){value9 = 0;}
    else{
	index9 = ((y-1)*w) + (x-1);
	initial9 = board[index9];
	value9 = board[index9] - '0';
    }
    
	if (value == 1){
		if (value2==1){
			sum1 += 1;
		}
		if (value3==1){
			sum1 += 1;
		}
		if (value4==1){
			sum1 += 1;
		}
		if (value5==1){
			sum1 += 1;
		}
		if (value6==1){
			sum1 += 1;
		}
		if (value7==1){
			sum1 += 1;
		}
		if (value8==1){
			sum1 += 1;
		}
		if (value9==1){
			sum1 += 1;
		}
	}

	else{
		if (value2==1){
			sum2 += 1;
		}
		if (value3==1){
			sum2 += 1;
		}
		if (value4==1){
			sum2 += 1;
		}
		if (value5==1){
			sum2 += 1;
		}
		if (value6==1){
			sum2 += 1;
		}
		if (value7==1){
			sum2 += 1;
		}
		if (value8==1){
			sum2 += 1;
		}
		if (value9==1){
			sum2 += 1;
		}

	}

	if((sum1==2) || (sum1==3)){
		alive = '1';
	}
	else if((sum2==3)){
		alive = '1';
	}
	else{
		alive = '0';
	}
	
	return alive;
}









void conwayStep (char *board, int w, int h){
	int x = 0; int y = 0; char move = ' '; int index = 0; char initial = ' '; 
	int size =0; size = (w*h) + 5;
	char *string = malloc(size*sizeof(char));
	strcpy(string,board);	
	for (x=0;x<w;x++){
		for(y=0;y<h;y++){
			move = cellTest (string, w, h, x, y);
			if (move == '1'){
				index = (y*w) + x;
				board[index] = '1';
			}
			else{
				index = (y*w) + x;
				board[index] = '0';
			}
		}
	}
	free(string);
}




// This function is an early Christmas present.  Happy Birthday! 
void printConway (char *board, int w, int h) {
	for (int j = 0; j < h; j++) {
		if (j == 0) {
			printf(" ");
			for (int i = 0; i < w; i++) {
				printf("%1d",i);
			}
		}
		
		printf("\n%1d",j);
		for (int i = 0; i < w; i++) {
			if (*(board + j*w + i) == '1') {
				printf("X");
			} else if (*(board + j*w + i) == '0') {
				printf(" ");
			}		
		}
	}
	printf("\n\n");
}

int main () {
	char *board;  
	
	FILE *f1 = fopen("test1.conway", "r");
	int size_w;
	int size_h;
	fscanf(f1, "%d\n", &size_w);
	fscanf(f1, "%d\n", &size_h);
	
	printf("w = %d\n", size_w);
	printf("h = %d\n", size_h);
	
	board = (char*)malloc(size_h*size_w*sizeof(char));
	if (board == NULL) {
		printf("Runtime Error: Not Enough Memory!\n");
	}
	fread(board, sizeof(char), size_w*size_h, f1);
	
	printConway(board, size_w, size_h);

	cellTest(board, size_w, size_h, 0,0);
	cellTest(board, size_w, size_h, 0,6);
	cellTest(board, size_w, size_h, 7,3);
	cellTest(board, size_w, size_h, 3,3);
	cellTest(board, size_w, size_h, 2,2);
	cellTest(board, size_w, size_h, 7,2);
	cellTest(board, size_w, size_h, 2,5);		
	cellTest(board, size_w, size_h, 8,5);
	cellTest(board, size_w, size_h, 6,0);

    /* Results of above tests
     * 
     * For cell (0,0), which is dead, we found 1 neighbor(s).  Cell remains lifeless. 
     * For cell (0,6), which is dead, we found 0 neighbor(s).  Cell remains lifeless. 
     * For cell (7,3), which is dead, we found 6 neighbor(s).  Cell remains lifeless. 
     * For cell (3,3), which is dead, we found 1 neighbor(s).  Cell remains lifeless. 
     * For cell (2,2), which is dead, we found 2 neighbor(s).  Cell remains lifeless. 
     * For cell (7,2), which is alive, we found 5 neighbor(s).  Cell is killed! 
     * For cell (2,5), which is alive, we found 2 neighbor(s).  Cell survives. 
     * For cell (8,5), which is dead, we found 3 neighbor(s).  Cell comes to life! 
     * For cell (6,0), which is dead, we found 1 neighbor(s).  Cell remains lifeless.
     */ 

	for (int q = 0; q < 26; q++) {
		printf(">><<>><<>><<>><<>><<\n");
		conwayStep(board, size_w, size_h);
		printf("After conway step %d:\n", q);
		printConway(board, size_w, size_h);
	}
		
	free(board);
	fclose(f1);
}
