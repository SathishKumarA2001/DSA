#include<stdio.h>
#include<stdlib.h>

void sort(int* arr,int size){
    for (int i = 0; i <= size; i++){
        for (int j = i+1; j <= size; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
}

void bSearch(int *arr,int val,int size){
    int mid;
    int high=size,low=0;
    while(low<=high){
        mid = low+(high-low)/2;
       if(arr[mid] == val){
            printf("Index value of searched key: %d",mid);
            break;
       } else if(arr[mid]>val){
            high = mid-1;
       }else if(arr[mid] < val){
            low = mid+1;
       }
        printf("\n%d %d %d\n",high,low,mid);
    }
}

int main(){
    int arr[6] = {4,3,6,7,9,8};
    int val = 3;    
    int size = 5;
    sort(arr,size);
    bSearch(arr,val,size);
    
}