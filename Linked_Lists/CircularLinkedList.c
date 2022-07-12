#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* next;
};

struct node* head;
struct node* current;

void print() {
   struct node *ptr = head;
   if(head != NULL) {
      while(ptr->next != ptr) {     
         printf("-> %d\t",ptr->key);
         ptr = ptr->next;
      }
      printf("\n");
   }
}

int isEmpty() {
   return head == NULL;
}

int InsertFirst(int key){
    struct node* link = (struct node*)malloc(sizeof(struct node));
    link->key = key;
    
    if(isEmpty()){
        head = link;
        link->next = head;
    }else{
        link->next = head;
        head = link;
    }
}

struct node* deleteFirst(){
    struct node* temp = head;
    if(head->next == head){
        head = NULL;
        return temp;
    }else{
        head = head->next;
    }
    return temp;
}

int main(){
    InsertFirst(50);
    InsertFirst(10);
    InsertFirst(20);
    InsertFirst(30);
    print();
    struct node* n = deleteFirst();
    printf("%d",n->key);
    print();
}