import java.util.Collections;
import java.util.PriorityQueue;

public class runningMedian {
  PriorityQueue<Integer>pq1;
  PriorityQueue<Integer>pq2;
  public runningMedian() {
    pq1=new PriorityQueue<>();
    pq2=new PriorityQueue<>(Collections.reverseOrder());
  }
    
  public void addNum(int num) {
    if(pq2.size()==0 || pq2.peek()>=num){
      pq2.offer(num);
    }
    else{
      pq1.offer(num);
    }
    if(pq2.size()>pq1.size()+1){
      pq1.offer(pq2.poll());
    }
    else if(pq1.size()>pq2.size()){
      pq2.offer(pq1.poll());
    }
  }
    
  public double findMedian() {
    if(pq2.size()>pq1.size()){
      return Double.valueOf(pq2.peek());
    }
    else{
      return Double.valueOf((pq1.peek()+pq2.peek()))/2;
    }
  }
  public static void main(String[] args) {
    runningMedian rm = new runningMedian();
    int[] nums = {5, 15, 1, 3};

    for (int num : nums) {
      rm.addNum(num);
      System.out.println("Added: " + num + ", Current Median: " + rm.findMedian());
    }
  }
}


