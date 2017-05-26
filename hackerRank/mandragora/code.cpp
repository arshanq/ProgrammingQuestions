#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> vec(n);
        for(int i = 0 ; i < n ; i++) {
            int tmp;
            cin>>tmp;
            vec[i] = tmp;
        }
        sort(vec.begin(), vec.end());
        vector<int> cum(n);
        cum[n-1] = vec[n-1];
        for(int i = n-2;i>=0;i--) {
            cum[i] = cum[i+1] + vec[i];
        }
        long long maxSum = 0;
        for(int i = 0; i< n; i++) {
            long long p = cum[i] * (i + 1);
            maxSum = maxSum > p ? maxSum : p;
        }
        cout<<maxSum<<endl;
    }
    return 0;
}

