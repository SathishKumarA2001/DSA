#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;

void Insert(int data){
    struct node* link = (struct node*)malloc(sizeof(struct node)); 
    link->data = data;
    link->next = head;
    head = link;
}

void push(struct node** head_ref,int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void prev_push(struct node* prev_node,int data){
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node; 
}

void append(struct node** head_ref,int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node* last = *head_ref;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void print(){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void main(){   
    Insert(1);
    Insert(2);
    Insert(3);
    print();
    //prev_push(head->next,4);
    append(&head,4);
    append(&head,5);
    print();
}