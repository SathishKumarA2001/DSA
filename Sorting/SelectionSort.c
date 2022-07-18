#include<stdio.h>
#define SIZE 8

void selection_Sort(int *a){
    int indexOfMinVal;
    for (int i = 0; i < SIZE-1; i++){
        indexOfMinVal = i;
        for (int j = i+1; j < SIZE; j++){  //Looping to find a minimum value by comparing between i and j
            if(a[indexOfMinVal] > a[j]){
                indexOfMinVal = j;
            }
        }
        if (indexOfMinVal != i){    // If the index of Minimum value changed it swaps;
            int temp = a[indexOfMinVal];
            a[indexOfMinVal] = a[i];
            a[i] = temp;
        }   
    }
}

int main(){
    int a[SIZE] = {4,6,2,3,1,8,7,5};
    selection_Sort(a);
    for (int i = 0; i < SIZE; i++){
        printf("%d\t",a[i]);
    }
    
}