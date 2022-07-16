#include<stdio.h>
#include<stdlib.h>
/* My Function*/
void BubbleSort(int *arr,int SIZE){
    int count=0;
    for (int i = 0; i <SIZE; i++){
        for (int j = i; j <SIZE; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            count++;
        }
        count++;
    }
    printf("%d\n",count);
}

// Efficient function

// void BubbleSort(int *arr,int SIZE){
//     int count = 0;
//     for (int i = 0; i <SIZE; i++){
//         for (int j = 0; j <SIZE-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//          count++;   
//         }
//         //count++;
//     }
//     printf("%d\n",count);    
// }

int main(){
    int arr[] = {3,6,2,9,20,12,40,45,15};
    size_t SIZE = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,SIZE);
    for (int i = 0; i < SIZE; i++){
        printf("%d\t",arr[i]);
    }
    
}