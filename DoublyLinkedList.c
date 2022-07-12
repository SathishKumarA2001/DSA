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

struct node* delete(int key){
    struct node *current = head;
    struct node *previous = NULL;
    struct node *next = NULL;

    if(head == NULL){
        return NULL;
    } 

    while(current->data != key){
        if(current->next == NULL){
            return NULL;
        }else{
            previous = current;
            current = current->next;
        }
    }

    if(current == head){
        head = head->next;
    }else{
        current->prev->next = current->next;
    }
    if(current == last){
        last = last->prev;
    }else{
        current->next->prev = current->prev;
    }
    return current;
    
}

int InsertAfter(int key,int newData){
    struct node *current = head;
    
    if(current == NULL){
        return 0;
    }

    while(current->data != key){
        if(current->next == NULL){
            return 0;
        }else{
            current = current->next;
        }
    }

    struct node* link = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    link->data = newData;
    
    if(current == last){
        link->next = NULL;
    }else{
        link->next = current->next;
        current->next->prev = link;
    }
    link->prev = current;
    current->next = link;

    return 1;
}

int main(void){
    InsertFirst(10);
    InsertFirst(20);
    InsertFirst(30);
    //struct node* temp = delete(10);
    //printf("%d\n",temp->data);
    print();
    InsertAfter(20,60);
    print();
    // InsertLast(40);
    // InsertLast(50);
    // InsertLast(60);
    //print();
    //displayForward();
    //displayBackward();
}