#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

struct node{
    char *name;
    char *tea;
    struct node *left;
    struct node *right;

}; typedef struct node Node;

int depth(struct node *ROOT){
    int left = 0; int right = 0;
    if(ROOT == NULL){
        return 0;
    }
    else{
        left = depth(ROOT->left);
        right = depth(ROOT->right);

        if (left > right){
            return(left + 1);
        }
        else{
            return(right+1);
        }  

         
    }

}

/* int df2s(struct node *ROOT,char *NAME){
    int left = 0; int right = 0;  int result = 0;
    result = strcmp(ROOT->name,NAME); int result1 = 0; int result2 =0; int exams=0;
    if(ROOT != NULL){
        if(result == 0){
            return (exams + 1);
        }
        else if(ROOT->left != NULL){
            result1 = strcmp(ROOT->left->name,NAME);
            if(result1 == 0){
                return (exams + 1);
            }
            else{
                return (dfs(ROOT->left,NAME) + 1);
            }
            
            }
        else if (ROOT->right != NULL){
            result2 = strcmp(ROOT->right->name,NAME);
            if(result2 == 0){
                return (exams + 1);
            }
            else{
                return (dfs(ROOT->right,NAME)+1);
            }
        }
           
    }

}  */

int dfs2(struct node *ROOT,char *NAME, int *exam){
    int result = 0;
    result = strcmp(ROOT->name,NAME); int found=0; 
    
    if(result == 0){
        found = 1;           
    }
    *exam += 1;    
    if((found!= 1)&&(ROOT->left != NULL)){
           found = dfs2(ROOT->left,NAME,exam);
    }
    if((found!= 1)&&(ROOT->right != NULL)){
            found = dfs2(ROOT->right,NAME,exam);
            
    } 
    
    return found;
    
}
int dfs(Node *ROOT, char *NAME){
    int exam = 0;
    int x = dfs2(ROOT,NAME, &exam);
    if(x == 1){
        return exam ;        
    }
    else if (x == 0){
        return -1;
    }


}
    

int main() {
    /* Testing code ^_^ */
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
     
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
    
}