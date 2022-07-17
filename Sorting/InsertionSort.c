#include<stdio.h>

// Own Logic, complexity is O(n^2)

void Insertion_Sort(int *a,int SIZE){
    int i=0;
    int count=0;
    while(i < SIZE-1){
        if(a[i]>a[i+1]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            i=0;
            count++;
        }else{
            i++;
        }
    }
    printf("%d\n",count);
}

// ALgorithmic Approach in web has same O(n2)

// void Insertion_Sort(int *a,int SIZE){
//     int Insert,position;
//     for (int i = 1; i < SIZE; i++){  
//         Insert = a[i];
//         position = i;

//         while(position > 0 && a[position-1]>Insert){
//             a[position] = a[position-1];
//             position--;
//         }

//         if(position != i){
//             a[position] = Insert;
//         }
//     }
// }

int main(){
    int a[] = {4,6,3,2,1,9,7};
    size_t SIZE = sizeof(a)/sizeof(a[0]);
    Insertion_Sort(a,SIZE);

    for (int i = 0; i < SIZE; i++){
        printf("%d\t",a[i]);
    }
    
}