import java.io.*;
import java.util.*;

public class Solution {
    
    private List<Edge> list;
    private int[] arr;
    int N;
    
    public Solution(List<Edge> list,int N) {
        this.list = list;
        this.N = N;
        arr = new int[N+1];
        for(int i=1;i<=N;i++) arr[i]=i;
    }
    
    private int findRoot(int node) {
        return this.arr[node] == node ? node : findRoot(this.arr[node]);
    }
    
    private void union(int x, int v) {
        this.arr[findRoot(x)]=findRoot(v);
    } 
    
    public long minWeight() {
        long minSum  = 0;
        for(Edge edge:this.list) {
       //     System.out.println("U: " + edge.u + " V: " + edge.v + " wt:" + edge.wt);
            if(findRoot(edge.u) != findRoot(edge.v)) {
          //      System.out.println("Picked");
                minSum+= edge.wt;
                union(edge.u, edge.v);
            }
        }
        return minSum;
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int N,M,u,v,wt;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        List<Edge> list = new ArrayList<>(M);
        for(int i=0;i<M;i++) {
            u = sc.nextInt();
            v = sc.nextInt();
            wt = sc.nextInt();
            list.add(new Edge(u,v,wt));
        }
        Collections.sort(list, Collections.reverseOrder());
        System.out.println(new Solution(list, N).minWeight());
    }
    
    private static class Edge implements Comparable<Edge> {
        int u,v,wt;
        
        public Edge(int u,int v, int wt) {
            this.u = u;
            this.v = v;
            this.wt = wt;
        }
        
        public int compareTo(Edge edge) {
            if(this.wt!= edge.wt) return edge.wt-this.wt;
            return edge.u+edge.v -this.u-this.v;
        }
        
    }
}