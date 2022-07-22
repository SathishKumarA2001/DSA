#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

struct vertex {
    char label;
    bool visited;
};

struct vertex *vertices[MAX];
int vertexCount = 0;

void add_vertex(char label){
    struct vertex *v1 = (struct vertex*)malloc(sizeof(struct vertex));
    v1->label = label;
    v1->visited = false;
    vertices[vertexCount++] = v1;
}
int adj[MAX][MAX] = {0};

void add_edge(int start, int end){
    adj[start][end] = 1;
    adj[end][start] = 1;
}

void display_vertices(){
    struct vertex **v = vertices;
    for (int i = 0; i < vertexCount; i++){
        printf("%c %d\n",v[i]->label,v[i]->visited);        
    }
    
}

void display_edges(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(adj[i][j] == 1 ){
                printf("[%d<->%d]\t",i,j);
            }
        }
    }
}

int stack[MAX];
int top = -1;

void push(int label){
    stack[++top] = label;
}
void pop(){
    stack[top--] = -1;
}
int peek(){
    return stack[top];
}
bool isEmpty(){
    return top == -1; 
}

void display_vertex(char label){
    printf("%c\t",label);
}

int getAdjUnvisitedVertex(int vertexIndex){
    for (int i = 0; i < vertexCount; i++){
        if(adj[vertexIndex][i] == 1 && vertices[i]->visited == false){
            return i;
        }
    }
    return -1;
}

void deapthFirstSearch(){
    vertices[0]->visited = true;
    display_vertex(vertices[0]->label);
    push(0);

    while (!isEmpty()){
        int unvisitedVertex = getAdjUnvisitedVertex(peek());
        if(unvisitedVertex == -1){
            pop();
        }else{
            vertices[unvisitedVertex]->visited = true;
            display_vertex(vertices[unvisitedVertex]->label);
            push(unvisitedVertex);
        }
    }
    
    for (int i = 0; i < vertexCount; i++){
        vertices[i]->visited = false;
    }
    
}

int main(){
    add_vertex('S'); //0
    add_vertex('A'); //1
    add_vertex('B'); //2
    add_vertex('C'); //3
    add_vertex('D'); //4
    display_vertices();

    add_edge(0, 1);    // S - A
    add_edge(0, 2);    // S - B
    add_edge(0, 3);    // S - C
    add_edge(1, 4);    // A - D
    add_edge(2, 4);    // B - D
    add_edge(3, 4);    // C - D

    //display_edges();
    deapthFirstSearch();
}
