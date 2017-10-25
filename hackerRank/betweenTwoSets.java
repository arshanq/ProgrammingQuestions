import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    static int find_gcd(int a, int b) {
        if(b==0) return a;
        return find_gcd(b, a%b );
    }
    
    static int find_lcm(int a, int b) {
        return (a*b)/ find_gcd(a, b);
    }

    static int getTotalX(int[] a, int[] b) {
        // Complete this function
        int lcm = a[0];
        for(int i = 1; i< a.length; i++) {
            lcm = find_lcm(lcm, a[i]);
        }
        int gcd = b[0];
        for(int i=1;i<b.length;i++) {
            gcd = find_gcd(gcd, b[i]);
        }
        if(gcd %lcm !=0) return 0;
        int count = 0;
        for(int i=lcm; i<=gcd;i+=lcm) {
            if(gcd%i == 0) count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for(int a_i = 0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        int[] b = new int[m];
        for(int b_i = 0; b_i < m; b_i++){
            b[b_i] = in.nextInt();
        }
        int total = getTotalX(a, b);
        System.out.println(total);
        in.close();
    }
}
