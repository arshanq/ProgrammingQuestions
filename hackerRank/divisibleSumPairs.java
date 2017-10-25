import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int divisibleSumPairs(int n, int k, int[] ar) {
        // Complete this function
        int mod[] = new int[k];
        for(int i =0;i<ar.length;i++) {
            mod[ar[i]%k]++;
        }
        int sum = 0;
        sum += (mod[0]*(mod[0] - 1)) / 2;
        for(int i=1; i<=k/2 && i!= k-i;i++) {
            sum+= mod[i] * mod[k-i];
        }
        if(k%2==0 ) {
            sum+= mod[k/2]* (mod[k/2] - 1) /2;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int[] ar = new int[n];
        for(int ar_i = 0; ar_i < n; ar_i++){
            ar[ar_i] = in.nextInt();
        }
        int result = divisibleSumPairs(n, k, ar);
        System.out.println(result);
    }
}
