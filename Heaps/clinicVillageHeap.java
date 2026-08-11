import java.util.*;
public class clinicVillageHeap {
    static class Village implements Comparable<Village>{
        int clinic;
        int population;
        Village(int population,int clinic){
            this.population=population;
            this.clinic=clinic;
        }
        double load(){
            return (double)population/clinic;
        }
        @Override
        public int compareTo(Village other){
            if(this.load()>other.load())return -1;
            if(this.load()<other.load())return 1;
            return 0;
        }
    }

    public static void main(String[] args) {
        int k=5;
        int n=3;
        int[] arr={200,20,50};
        PriorityQueue<Village>pq=new PriorityQueue<>();
        for(int i=0;i<arr.length;i++){
            pq.offer(new Village(arr[i], 1));
            k--;
        }
        while(k--!=0){
            Village x=pq.poll();
            x.clinic++;
            pq.offer(x);
        }
        System.out.printf("%.2f",pq.element().load());
    }
    
}
