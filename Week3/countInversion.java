import java.util.*;
class countInversion{
  private static void merge(int[] arr,int l,int mid,int r){
    int[] temp=new int[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=r){
      if(arr[i]<arr[j]){
        temp[k++]=arr[i++];
      }
      else{
        temp[k++]=arr[j++];
      }
    }
    while(i<=mid){
      temp[k++]=arr[i++];
    }
    while(j<=r){
      temp[k++]=arr[j++];   
    }
    for(int d=0;d<temp.length;d++){
      arr[d+l]=temp[d];
    }
  }
  private static int divide(int[] arr,int l,int r){
    if(l>=r)return 0;
    int mid=l+(r-l)/2;
    int count=divide(arr,l,mid)+divide(arr,mid+1,r);
    int j=mid+1;
    for(int i=l;i<=mid;i++){
      while(j<=r && arr[i]>arr[j]){
        j++;
      } 
      count+=j-(mid+1);
    }
    merge(arr,l,mid,r);
    return count;
  }
    public static void main(String[] args) {
        int[] arr={1,2,4,1,3,5};
        // int[] arr={2,3,4,5,6};

        System.out.println(divide(arr,0,arr.length-1));
    }
}