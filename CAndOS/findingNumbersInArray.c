#include<stdio.h>
int findNumberWithFourOccurence(int arr[],int n){
  int ans=0;
  for(int bit=0;bit<32;bit++){
    int count=0;
    for(int i=0;i<n;i++){
      if(arr[i]&1<<bit){
        count++;
      }
    }
    if(count%3!=0){
      ans|=1<<bit;
    }
  }
  return ans;
}
int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", findNumberWithFourOccurence(arr, n));
    return 0;
}






























