#include<stdio.h>
#define MAX 8

int a[8] = {5,6,4,7,3,8,2,9};

//Own logic function worst case O(n(n2))
void shell_sort(){
    int loopCount =0;
    for (int count = MAX/2; count > 0; count/=2){
        for (int i = 0; i < count; i++){
            for (int j = count; j < MAX; j++){
                if(a[i] > a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                loopCount++;
            }
        }
    }

    for (int i = 1; i < MAX; i++){
        int value = a[i];
        int position = i;

        while (a[position-1] > value && position > 0){
            loopCount++;
            a[position] = a[position-1];
            position--;
        }
        if (position !=i){
            a[position] = value;
        }
        
    }
printf("%d\n",loopCount);    
    
}

// ALgorithmic logic O(n)
// void ShellSort(int n){

//     for (int gap = n/2; gap > 0; gap /= 2){

//         for (int i = gap; i < n; i += 1){
//             int temp = a[i];
//             int j;            
//             for (j = i; j >= gap && a[j - gap] > temp; j -= gap){
//                 a[j] = a[j - gap];
//             }
//             a[j] = temp;
//         }
//     }
// }

int main(){
    //ShellSort(MAX);
    shell_sort();
    for (int i = 0; i < MAX; i++){
        printf("%d\t",a[i]);
    }
    
}