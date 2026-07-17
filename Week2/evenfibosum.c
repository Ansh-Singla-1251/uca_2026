#include<stdio.h>
int optiFibo(int n){
    int n1=0;
    int n2=2;
    int n3;
    int sum=0;
    if(n<2)return 0;
    while(n1<=n){
        sum+=n1;
        n3=4*n2+n1;
        n1=n2;
        n2=n3;
    }
    return sum;
}
int nFibo(int n){
    int n1=0;
    int n2=1;
    int n3;
    int sum=0;
    if(n<2)return 0;
    while(n1<=n){
        if(n1%2==0)sum+=n1;
        n3=n1+n2;
        
        n1=n2;
        n2=n3;
    }
    return sum;
}
int main(){
    int n=50;
    printf("Optimized: %d, O(n): %d",optiFibo(n),nFibo(n));
}