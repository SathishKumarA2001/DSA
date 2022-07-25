#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void Traversal(struct node* root) {
   if(root != NULL) {
      Traversal(root->left);
      printf("%d\n",root->key);
      Traversal(root->right);
   }
}

void TDS(int key){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    struct node *current,*parent;

    n->key = key;
    n->left = NULL;
    n->right = NULL;

    if(root == NULL){
        root = n;
    }else{
        current = root;
        while(1){
            parent = current;
            if(key > current->key){
                current=current->right;
                if(current == NULL){
                    parent->right = n;
                    return;
                }
            }else if(key < current->key){
                current = current->left;
                if(current == NULL){
                    parent->left = n;
                    return;
                }
            }    
        }
    }
}

void Search(struct node *root,int key){
    struct node* current = root;
    if(current == NULL){
        printf("Empty");
        return;
    }
    while (1){
        if(key == current->key){
            printf("Node [%d]",key);
            return;
        }
        if(key > current->key){
            current = current->right;
        }else if(key < current->key){
            current = current->left;
        }
        if(current == NULL){
            printf("Not a node");
            return;
        }
    }
}

void Insert(int key){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    struct node *current = root;
    struct node *parent;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    if (root == NULL){
        root = n;
    }else{
        while(1){
            parent = current;    
            
            if(current->key > key){
                current = current->left;
                if (current == NULL){
                    parent->left = n;
                    return;
                }         
            }else if(current->key <= key){
                current = current->right;
                if (current == NULL){
                    parent->right = n;
                    return;
                }         
            }
        }
    }
}

int main(int argc,char *argv[]){
    TDS(10);
     TDS(20);
      TDS(5);
       TDS(3);
        TDS(50);
    //Traversal(root);
    //Search(root,atol(argv[1]));  //atol() convert const *char to integer
    Insert(60);
    Insert(7);
    Insert(45);
    Insert(12);
    Traversal(root);
}