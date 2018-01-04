import java.io.*;
import java.util.*;

public class gridlandMetro {

    public static long mergeIntervals(List<Interval> list) {
        Stack<Interval> stack = new Stack<>();
        stack.push(list.get(0));
        for(int i=1; i<list.size();i++) {
            if(list.get(i).start <= stack.peek().end) {
                int a =  list.get(i).end ;
                int b = stack.peek().end;
                stack.peek().end = a > b? a:b;
            } else {
                stack.push(list.get(i));
            }
        }
        long sum =0;
        while(stack.size() >0) {
            Interval interval = stack.pop();
            sum+= interval.end - interval.start +1;
         //   System.out.println("Start: " + interval.start + " End: " + interval.end);
        }
        return sum;
        
    }
    
    public static long solve(Map<Integer, List<Interval>> map , int N, int M) {

        long compute = 0;
        for(Map.Entry<Integer, List<Interval>> entry: map.entrySet()) {
            Collections.sort(entry.getValue());
            compute+= mergeIntervals(entry.getValue());
        }
        
        long sum = (long)N* (long)M;
        System.out.println("Product " + sum + " compute " + compute);
        sum-=compute;
        return sum;
    }
    
    public static void printList(List<Interval> list) {
        for(Interval intv: list) {
            System.out.println("Start: " + intv.start + " End: " + intv.end);
        }
    }
    
    public static void main(String[] args) {
        int N,M,K;
        Scanner sc  = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        int row;
        Map<Integer, List<Interval>> map = new HashMap<>();
        for(int i=0;i<K;i++) {
            row = sc.nextInt();
            if(!map.containsKey(row)) map.put(row, new ArrayList<>());
            Interval interval = new Interval();
            interval.start = sc.nextInt();
            interval.end = sc.nextInt();
            map.get(row).add(interval);
        }
        System.out.println(solve(map, N, M));
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
    
    
    private static class Interval implements Comparable<Interval> {
        
        int start;
        int end;
       
        public int compareTo(Interval obj) {
         if(this.start < obj.start) return -1;
        /* else if(this.start == obj.start) {
             return this.end < obj.end ? -1: 1;
         }*/
         return 1;
        }
    }
}