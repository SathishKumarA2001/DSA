#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* last = NULL;
struct node* current = NULL;

int isEmpty(){
    return head == NULL;
}
void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("-> %d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void InsertFirst(int data){
    struct node* link = (struct node*)malloc(sizeof(struct node));
    link->data = data;
    if(isEmpty()){
        last = link;
    }else{
        head->prev = link;
    }
    link->next = head;
    head = link;
}

void InsertLast(int data){
    struct node* link = (struct node*)malloc(sizeof(struct node));
    link->data = data;
    if(link == NULL){
        last=link;
    }else{
        last->next = link;
        link->prev = last;
    }
    last=link;
}

void displayForward(){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("-> %d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayBackward(){
    struct node *ptr = last;
    while (ptr != NULL){
        printf("-> %d\t",ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");    
}

struct node* deleteFirst(){
    struct node *ptr = head;
    if(head->next == NULL){
        last = NULL;
    }else{
        head->next->prev = NULL;
    }
    
    head = head->next;
    return ptr;
}

struct node* deleteLast(){
    struct node *ptr = last;
    if(head->next == NULL){
        last = NULL;
    }else{
        last->prev->next = NULL;
    }
    last = last->prev;
    return ptr;
}

int main(void){
    InsertFirst(10);
    InsertFirst(20);
    InsertFirst(30);
    struct node* temp = deleteLast();
    printf("%d\n",temp->data);
    print();
    // InsertLast(40);
    // InsertLast(50);
    // InsertLast(60);
    //print();
    //displayForward();
    //displayBackward();
}