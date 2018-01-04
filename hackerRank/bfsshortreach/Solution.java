import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static int[] solve(Map<Integer, List<Integer>> map, int startingNode, int maxNodes) {
       Queue<Integer> list = new LinkedList<>();
       list.add(startingNode);
       int[] visited = new int[maxNodes+1];
       Arrays.fill(visited, -1);
       int[] cost = new int[maxNodes+1];
       Arrays.fill(cost, Integer.MAX_VALUE);
       cost[startingNode] = 0;
       while(list.size() > 0) {
           int node = list.poll();
           if(visited[node] == -1) {
               List<Integer> neighbours = map.getOrDefault(node, new ArrayList<>());
               for(int nb: neighbours) {
                   cost[nb] = cost[nb] < cost[node] + 6 ? cost[nb] : cost[node] + 6;
                   list.add(nb);
               }
               visited[node] = 1;
           }
       }
        for(int i=0;i<cost.length;i++) if(cost[i] == Integer.MAX_VALUE) cost[i] = -1;
        //System.out.println(cost.length);
        return cost;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for(int a0 = 0; a0 < q; a0++){
            Map<Integer, List<Integer>> map = new HashMap<>();
            int n = in.nextInt();
            int m = in.nextInt();
            for(int a1 = 0; a1 < m; a1++){
                int u = in.nextInt();
                int v = in.nextInt();
                List<Integer> listU ;
                //map.getOrDefault(u, new ArrayList<>());
                if(!map.containsKey(u)) {
                    map.put(u,new ArrayList<>());
                }
                List<Integer> listV ;
                if(!map.containsKey(v)) {
                    map.put(v, new ArrayList<>());
                }
                //map.getOrDefault(v, new ArrayList<>());
                listU = map.get(u);
                listV = map.get(v);
                listU.add(v);
                listV.add(u);
            }
            int s = in.nextInt();
            int[] result = solve(map, s, n);
            for(int i=1;i<result.length;i++) {
                if(i!=s)
                System.out.print(result[i] +" ");
            }
            System.out.println();
        }
        in.close();
    }
}
