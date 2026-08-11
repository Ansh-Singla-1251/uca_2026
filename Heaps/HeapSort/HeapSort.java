import java.util.Arrays;
import java.util.Random;
public class HeapSort {
  static void heapify(int[] arr, int n, int i) {
    while (true) {
      int largest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      if (left < n && arr[left] > arr[largest]) {
        largest = left;
      }
      if (right < n && arr[right] > arr[largest]) {
        largest = right;
      }
      if (largest == i) {
        break;
      }
      int temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      i = largest;
    }
  }
  static void heapSort(int[] arr) {
    int n = arr.length;
    for (int i = n / 2; i >= 0; i--) {
      heapify(arr, n, i);
    }
    for (int end = n - 1; end > 0; end--) {
      int temp = arr[0];
      arr[0] = arr[end];
      arr[end] = temp;
      heapify(arr, end, 0);
    }
  }
  static int[] generateArray(int n, String type) {
    int[] arr = new int[n];
    Random rand = new Random();
    if (type.equals("random")) {
      for (int i = 0; i < n; i++){
        arr[i] = rand.nextInt(100000);
      }
    }
    else if (type.equals("ascending")) {
      for (int i = 0; i < n; i++){
        arr[i] = i;
      }
    } 
    else if (type.equals("descending")) {
      for (int i = 0; i < n; i++){
        arr[i] = n - i;
      }
    }
    return arr;
  }

  public static void main(String[] args) {
    int n = 75000; // adjust size for testing
    String[] cases = {"random", "ascending", "descending"};
    for (String type : cases) {
      int[] arr = generateArray(n, type);
      long start = System.nanoTime();
      heapSort(arr);
      long end = System.nanoTime();
      System.out.println(type + " array sorted? " + isSorted(arr));
      System.out.println(type + " case runtime: " + (end - start) / 1e6 + " ms");
    }
  }
  static boolean isSorted(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
      if (arr[i - 1] > arr[i]){
        return false;
      } 
    }
    return true;
  }
}
