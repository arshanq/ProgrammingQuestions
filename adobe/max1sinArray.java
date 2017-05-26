static int maxOnes(int [][]a, int N ) {
/*N: size of the array */
    int maxSum = 0, pos =0;
    for(int i=0;i<N;i++) {
        int sum = 0;
        for(int j = 0;j<N;j++) {
            sum+=a[i][j];
        }
        if(sum > maxSum) {
            pos = i;
            maxSum = sum;
        }
    }
    return pos;
}


