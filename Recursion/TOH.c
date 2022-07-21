#include<stdio.h>
#define MAX 3

int src[3] = {1,2,3};
int dest[3] = {0};
int aux[3] = {0};

void display(){
    printf("----------\n");
    for (int i = 0; i < MAX; i++){
        printf("%d\t%d\t%d\n",src[i],aux[i],dest[i]);
    }
}
// Tower of Honai own funny logic but it works anyway because recursion made me freak about this
int TOH(){
    do{
        for (int i = 0; i < MAX; i++){
            if(dest[2] == 0 || src[i] < dest[2]){
                dest[2] = src[i];
                src[i] = 0;
                display();
                if(dest[2] == 3){
                    src[2] = aux[1];
                    aux[1] = 0;
                    display();
                }                 
                if(dest[1] == 0){
                    dest[1] = aux[2];
                    aux[2] = 0;
                    display();
                }
                if(dest[0] == 0 && dest[2] == 3 && dest[1] == 2){
                    dest[0] = src[2];
                    src[2] = 0;
                    display();
                    break;
                }        
                continue;
            }else if(aux[2] == 0 || src[i] < aux[2]){
                aux[2] = src[i];
                src[i] = 0;
                display();
                if(dest[2] != 0 && dest[2] < aux[2]){
                    aux[1] = dest[2];
                    dest[2] = 0;
                    display();
                }
                continue;
            }
        } 
    } while(dest[0] != 1 && dest[1] != 2 && dest[2] != 3);
}

int main(){
    //display();
    TOH();
    //display();
    
}
