#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void Insert(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void print(){
    struct node* temp = head;

    while(temp != NULL){
        printf("Data : %d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(){
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int length(){
    struct node* current;
    int len=0;
    for (current = head; current != NULL; current=current->next){
        len++;
    }
    return len;
}

void sort(){
    struct node* temp;
    struct node* temp2;
    int sort,i=0,j=0;
    for (i=0; i<length()-1; i++){
        temp = head;
        temp2 = head->next;
        for (j=0;j<length()-1;j++){
            if(temp->data > temp2->data){
                sort =  temp->data;
                temp->data = temp2->data;
                temp2->data = sort;   
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
    }
}

int main(){
    for (int i = 1; i <= 5; i++){
        Insert(i);
    }
    print();
    reverse();
    print();
    sort();
    print();
}