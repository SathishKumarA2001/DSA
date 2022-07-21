#include<stdio.h>

int fibo(int n){

    //Implemented using Recursion
    static int n1 = 0,n2 = 1,n3;
    if(n>0){
        n3 = n1+n2;
        n1 = n2;
        n2 = n3;
        printf("%d\t",n3);
        return fibo(n-1);
    }

    // Implemented in iteraion 
    // int n=1;
    // while(fib<5000){
    //     printf("%d\t",fib);
    //     fib = fib+n;
    //     n = fib-n;
    // }
}

int main(){
    fibo(9);
}