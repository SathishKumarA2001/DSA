#include<stdio.h>
#include<stdbool.h>

const int MAX = 4;
int stack[4];
int top = -1;

bool isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if(top == MAX){
        return true;
    }else{
        return false;
    }
}

int peek(){
    return stack[top];
}

int push(int data){
    if(!isFull()){
        top +=1;
        stack[top] = data;
        return 0;
    }
    return 1;
}

int pop(){
    if(!isEmpty()){
        int temp = stack[top];
        top-=1;
        return temp;
    }else{
        return 1;
    }
}

int print(){
    int data;
    while(!isEmpty()){
        data = pop();
        printf("\n%d\n",data);
    }
}

int main(){
    for (int i = 10; i < 90; i+=10){
        if(isFull()){
            break;
        }
        push(i);
    }
    print();
}