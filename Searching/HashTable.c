#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct DataItem{
    int key;
    int data;
};
struct DataItem* Array[SIZE];

int HashCode(int key){
    return key%SIZE;
}

void insert(int key,int data){
    struct DataItem *d = (struct DataItem*)malloc(sizeof(struct DataItem));
    d->key = key;
    d->data = data;
    int index = HashCode(key);
    while(Array[index] != NULL && Array[index]->key != -1){
        ++index;
        //index %=SIZE;
    }
    Array[index] = d;
}

struct DataItem *Search(int key){
    int index = HashCode(key);
    
    while (Array[index] != NULL){
        if(Array[index]->key == key){
            return Array[index];
        }
        ++index;
        //index %= SIZE;   
    }
    return NULL;   
}

struct DataItem *Delete(int key){
    int index = HashCode(key);
    while(Array[index] != NULL){
        if(Array[index]->key == key){
            Array[index] = NULL;
            return Array[index];
        }
        ++index;
        index %= SIZE;
    }
    return NULL;
}

void Display(){
    for (int i = 0; i < SIZE; i++){
        if(Array[i] != NULL){
            printf("%d %d\n",Array[i]->key,Array[i]->data);
        }
    }
}
int main(){
    struct DataItem *emptyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    emptyItem->data = -1;
    emptyItem->key = -1;


   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
    Display();
    //Delete(3);
    //Display();
    struct DataItem *a =  Search(42);
    printf("%d",a->data);
}