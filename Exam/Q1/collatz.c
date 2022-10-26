#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

struct collatzNode {
	struct collatzNode *even;
	struct collatzNode *odd;
	int value;
} ;

typedef struct collatzNode node;

int *collatz (int n){
int val = 0; int size = 0; int* array; 
int i = 0;
size = 1;
array = malloc(2*sizeof(int));
array[0] = n;
while (n!=1){
	array = realloc(array,(size+1)*sizeof(int));
	if((n%2) != 0){
		n = (3*n) + 1;
		}
	else{
		n = n/2;
	}
	array[size] = n;
	size++;
}

int temp; int start = 0; int end = 0; 
end = (size - 1);
    while (start < end){
        temp = array[start];  
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    } 
/* for(i=0;i<size;i++){
    printf("%d\n",array[i]);
}      */
return array;
}

/* void constructhelper(node** tree, int *chain,int last, int i){
    int curr = 0;
    curr = chain[i];
    if (curr%2 == 0){
        if((*tree)->even == NULL){
            node *temp = (node*)malloc(sizeof(node));
            (temp)->even = NULL;
            (temp)->odd = NULL;
			(*tree)->even =temp;
        }
        if(curr == last){
            (*tree)->even->value = curr;
            return;
        }
        else{
            (*tree)->even->value = curr;
            return constructhelper((&(*tree)->even), chain, last, i);
        }

    }
    else{
        if((*tree)->odd == NULL){
            node *temp2 = (node*)malloc(sizeof(node));
            (temp2)->even = NULL;
            (temp2)->odd = NULL;
			(*tree)->odd =temp2;
            }
        if(curr == last){
            (*tree)->odd->value = curr;
            return;
        }
        else{
            (*tree)->odd->value = curr;
            return constructhelper((&(*tree)->odd), chain, last, i);
        }
    
}
} */

void constructhelper(node** tree, int *chain,int last, int i){
    if(chain[i-1] != last){
		if (chain[i]%2 != 0){
			if((*tree)->odd == NULL){
               (*tree)->odd = (node*)malloc(sizeof(node));
               (*tree)->odd->value = chain[i];
               (*tree)->odd->even = NULL;
               (*tree)->odd->odd = NULL;
               i++;
                constructhelper(&(*tree)->odd, chain, last, i);
				}
			else{
				i++;
               	constructhelper(&(*tree)->odd, chain, last, i);
            	}
        	}
		else{
			if((*tree)->even == NULL){
               (*tree)->even = (node*)malloc(sizeof(node));
               (*tree)->even->value = chain[i];
               (*tree)->even->even = NULL;
               (*tree)->even->odd = NULL;
                i++;
                constructhelper(&(*tree)->even, chain, last, i);
            }
			else{
                i++;
                constructhelper(&(*tree)->even, chain, last, i);
            }
        }
        
    }
}



void construct (node **tree, int *chain, int lastNumber){
	int i = 1;
	if(chain[0]!=lastNumber){
		constructhelper(tree,chain,lastNumber,i);
	}
}

void deconstructTree (node **tree){
	if((*tree) == NULL){
		return;
	}
	if((*tree)->even != NULL){
		deconstructTree(&((*tree)->even));
	}
	else if ((*tree)->odd != NULL){
		deconstructTree(&((*tree)->odd));
	}
	free((*tree));
	*tree = NULL;
}


void writeTreeHelper(node *tree, FILE *cfile){
	if (tree == NULL){
		return;
		}
	if(tree->even != NULL){
		fprintf(cfile,"\t%d -> %d\n",tree->even->value, tree->value);
		writeTreeHelper(tree->even, cfile);
		}
	if(tree->odd != NULL){
		fprintf(cfile,"\t%d -> %d\n", tree->odd->value, tree->value);
		writeTreeHelper(tree->odd, cfile);	
		}

}

void writeTreeToGraphviz (node *tree, char *filename){
	FILE *cfile = fopen(filename,"w");
	if (cfile == NULL){
		return;
	}
	char *intro = " ";
	intro = "digraph a {\n";
	fprintf(cfile, intro);
	writeTreeHelper(tree,cfile);
	char *end = " ";
	end = "}\n";
	fprintf(cfile,end);
	fclose(cfile);

}


int main () {

	int* chain = NULL;

	// Uncomment this section for Part A test cases
	chain = collatz(7);
	// Correct Sequence = 1, 2, 4, 8, 16, 5, 10, 20, 40, 13, 26, 52, 17, 34, 11, 22, 7
	chain = collatz(8);
	// Correct Sequence = 1, 2, 4, 8
	chain = collatz(9);
	// Correct Sequence = 1, 2, 4, 8, 16, 5, 10, 20, 40, 13, 26, 52, 17, 34, 11, 22, 7, 14, 28, 9
	chain = collatz(27);	
	// Correct Sequence = 1, 2, 4, 8, 16, 5, 10, 20, 40, 80, 160, 53, 106, 35, 70, 23, 46, 92, 184, 61, 122, 244, 488, 976, 325, 650, 1300, 433, 866, 1732, 577, 1154, 2308, 4616, 9232, 3077, 6154, 2051, 4102, 1367, 2734, 911, 1822, 3644, 7288, 2429, 4858, 1619, 3238, 1079, 2158, 719, 1438, 479, 958, 319, 638, 1276, 425, 850, 283, 566, 1132, 377, 754, 251, 502, 167, 334, 668, 1336, 445, 890, 1780, 593, 1186, 395, 790, 263, 526, 175, 350, 700, 233, 466, 155, 310, 103, 206, 412, 137, 274, 91, 182, 364, 121, 242, 484, 161, 322, 107, 214, 71, 142, 47, 94, 31, 62, 124, 41, 82, 27
	chain = collatz(35792);
	// Correct Sequence = 1, 2, 4, 8, 16, 5, 10, 20, 40, 13, 26, 52, 17, 34, 11, 22, 7, 14, 28, 56, 112, 37, 74, 148, 49, 98, 196, 65, 130, 43, 86, 172, 344, 688, 1376, 2752, 917, 1834, 611, 1222, 407, 814, 271, 542, 1084, 361, 722, 1444, 481, 962, 1924, 641, 1282, 427, 854, 1708, 569, 1138, 379, 758, 1516, 505, 1010, 2020, 4040, 8080, 2693, 5386, 1795, 3590, 7180, 2393, 4786, 1595, 3190, 1063, 2126, 4252, 1417, 2834, 5668, 1889, 3778, 1259, 2518, 839, 1678, 3356, 6712, 2237, 4474, 8948, 17896, 35792
	
	// notice how 27 is longer?!
	
	// End of Part 1 Test Cases */

	node* tree = NULL;
	tree = (node*)malloc(sizeof(node));
	tree->value = 1;
	tree->even = NULL;
	tree->odd = NULL; 
	
	// Uncomment this section for Part B test cases
	
	// These aren't technically collatz chains, but they will process the same way as collatz chains.
	
	int chain1[] = {1,2,3,4,5,6};
	int chain2[] = {1,7,8,10};
	int chain3[] = {1,7,9,12};
	
	construct(&tree, chain1, 6);
	construct(&tree, chain2, 10);
	construct(&tree, chain3, 12);
	
	// The tree should look like this:
	
	/* 1
	 * e- 2 
	 *   e- NULL
	 *	 o- 3
	 *     e- 4 
	 *       e- NULL
	 *       o- 5
	 *         e- 6
	 *           e- NULL
	 *           o- NULL
	 *         o- NULL
	 *     o- NULL
	 * o- 7
	 *   e- 8
	 *     e- 10
	 *       e- NULL
	 *       o- NULL
	 *     o- NULL
	 *   o- 9
	 *     e- 12
	 *       e- NULL
	 *       o- NULL
	 *     o- NULL
	 */	
	// */

	// Uncomment this section for Part C test cases
	
	deconstructTree(&tree);
	
	tree = (node*)malloc(sizeof(node));
	tree->value = 1;
	tree->even = (node*)malloc(sizeof(node));
	tree->odd = (node*)malloc(sizeof(node));
	tree->odd->value = 7;
	tree->odd->even = (node*)malloc(sizeof(node));
	tree->odd->even->value = 8;
	tree->odd->even->even = (node*)malloc(sizeof(node));
	tree->odd->even->odd = NULL;
	tree->odd->even->even->value = 10;
	tree->odd->even->even->even = NULL;
	tree->odd->even->even->odd = NULL;
	tree->odd->odd = (node*)malloc(sizeof(node));
	tree->odd->odd->value = 9;
	tree->odd->odd->even = (node*)malloc(sizeof(node));
	tree->odd->odd->even->value = 12;
	tree->odd->odd->even->even = NULL;
	tree->odd->odd->even->odd = NULL;
	tree->odd->odd->odd = NULL;
	tree->even->value = 2;
	tree->even->even = NULL;
	tree->even->odd = (node*)malloc(sizeof(node));
	tree->even->odd->value = 3;
	tree->even->odd->even = (node*)malloc(sizeof(node));
	tree->even->odd->odd = NULL;
	tree->even->odd->even->value = 4;
	tree->even->odd->even->even = NULL;	
	tree->even->odd->even->odd = (node*)malloc(sizeof(node));
	tree->even->odd->even->odd->value = 5;
	tree->even->odd->even->odd->even = (node*)malloc(sizeof(node));
	tree->even->odd->even->odd->odd = NULL;
	tree->even->odd->even->odd->even->value = 6;
	tree->even->odd->even->odd->even->odd = NULL;
	tree->even->odd->even->odd->even->even = NULL;

	writeTreeToGraphviz(tree, "testcase1.gv"); 
	// Compare the generated file to "testcase1.gv.test", provided in your exam package.  
	
	// */

    // Uncomment this section to generate a series of full collatz trees
 	//deconstructTree(&tree);   
    
	int n[5] = {10,20,50,100,500};
	for (int j = 0; j < 5; j++) {
		deconstructTree(&tree);
		tree = (node*)malloc(sizeof(node));
		tree->value = 1;
		tree->even = NULL;
		tree->odd = NULL; 
		for (int i = 1; i < n[j]; i++) {
			chain = collatz(i);
			construct(&tree, chain, i);
			free(chain);
		}
		char buf[50];
		snprintf(buf, 50, "collatz-%d.gv", n[j]);
	
		writeTreeToGraphviz(tree, buf);
	}
	// */ 
}
