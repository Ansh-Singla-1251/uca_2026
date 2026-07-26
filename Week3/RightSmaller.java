import java.util.*;
public class RightSmaller {
  static class Pair {
    int val;
    int idx;
    Pair(int val, int idx) {
      this.val = val;
      this.idx = idx;
    }
  }
  static int[] ans;
  public static void mergeSort(Pair[] arr, int left, int right) {
    if (left >= right) {
      return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }

  public static void merge(Pair[] arr, int left, int mid, int right) {
    Pair[] temp = new Pair[right - left + 1];
    int i = left;          
    int j = mid + 1;       
    int k = 0;            
    int rightCount = 0; 
    while (i <= mid && j <= right) {
      if (arr[j].val < arr[i].val) {
        rightCount++;
        temp[k++] = arr[j++];
      } 
      else {
        ans[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
      }
    }
    while (i <= mid) {
      ans[arr[i].idx] += rightCount;
      temp[k++] = arr[i++];
    }
    while (j <= right) {
      temp[k++] = arr[j++];
    }
    for (int x = 0; x < temp.length; x++) {
      arr[left + x] = temp[x];
    }
  }

  public static void main(String[] args) {
    int[] nums = {5, 2, 6, 1};
    int n = nums.length;
    ans = new int[n];
    Pair[] arr = new Pair[n];
    for (int i = 0; i < n; i++) {
      arr[i] = new Pair(nums[i], i);
    }
    mergeSort(arr, 0, n - 1);
    List<Integer> result = new ArrayList<>();
    for (int count : ans) {
      result.add(count);
    }
    for (int x : result) {
      System.out.print(x + " ");
    }
  }
}