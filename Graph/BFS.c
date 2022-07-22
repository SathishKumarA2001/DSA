#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

struct vertex {
    char label;
    bool visited;
};

struct vertex *vertices[MAX];
int vertexCount;
int adjVertex[MAX][MAX] = {0};

void display_vertices(){
    for (int i = 0; i < vertexCount; i++){
        printf("%c %d\n",vertices[i]->label,vertices[i]->visited);
    }
    
}

void display_edges(){
    for (int i = 0; i < vertexCount; i++){
        for (int j = 0; j < vertexCount; j++){
            if(adjVertex[i][j]){
                printf("%d<->%d\t",i,j);
            }
        }
        
    }
    
}

void add_vertex(int label){
    struct vertex *v = (struct vertex*)malloc(sizeof(struct vertex));
    v->label = label;
    v->visited = false;
    vertices[vertexCount++] = v;
}

void add_edge(int start,int end){
    adjVertex[start][end] = 1;
    adjVertex[end][start] = 1;
}
int queue[MAX];
int rear = -1,front = 0,queueCount=0;

int enqueue(int data){
    queue[++rear] = data;
    queueCount++;
}

int dequeue(){
    queueCount--;
    return queue[front++];
}

bool isEmpty(){
    return queueCount == 0;
}

void displayVertex(int vertexIndex){
    printf("%c \n",vertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex){
    for (int i = 0; i < vertexCount; i++){
        if (adjVertex[vertexIndex][i] == 1 && vertices[i]->visited == false){
            return i;
        }
    }
    return -1;
}

void BFS(){
    vertices[0]->visited = true;
    displayVertex(0);
    enqueue(0);
    int unvisitedVertex;

    while(!isEmpty()){
        int temp = dequeue();
        
        while((unvisitedVertex = getAdjUnvisitedVertex(temp)) != -1){
            vertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            enqueue(unvisitedVertex);
        }
    }        
    for(int i = 0;i<vertexCount;i++) {
        vertices[i]->visited = false;
    }
}

int main(){
   add_vertex('S');   // 0
   add_vertex('A');   // 1
   add_vertex('B');   // 2
   add_vertex('C');   // 3
   add_vertex('D');   // 4
   //display_vertices();
   
   add_edge(0, 1);    // S - A
   add_edge(0, 2);    // S - B
   add_edge(0, 3);    // S - C
   add_edge(1, 4);    // A - D
   add_edge(2, 4);    // B - D
   add_edge(3, 4);    // C - D
   //display_edges();
   BFS();
}