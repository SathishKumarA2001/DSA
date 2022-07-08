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

void print(){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* deletefirst(){
    struct node* temp = head;
    head = head->next;
    return temp;
}

struct node* prev_del(struct node* prev_node){
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return prev_node;
    }
    struct node* temp = prev_node->next;
    prev_node->next = temp->next;
    return temp; 
}

struct node* deletelast(){
    struct node* last = head;
    struct node* temp = NULL;
    while(last->next != NULL){
        temp = last;
        last = last->next;
    }
    last = temp;
    temp = temp->next;
    last->next = NULL; 
    return temp;
}

int main(){
    Insert(1);
    Insert(2);
    Insert(3);
    print();
    //struct node* temp = deletefirst();
    //struct node* temp = prev_del(head->next+2);
    struct node* temp = deletelast();
    printf("%d \n",temp->data);
    print();
}