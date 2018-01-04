#include <iostream>

using namespace std;
int temp[100000];

long int merge(int ar[], int lo, int mid, int hi) {
    int i = lo, j = mid, k = lo;
    long int count = 0;
    while(i<mid && j<=hi) {
        if(ar[i] <= ar[j]) {
            temp[k++] = ar[i++];
        }
        if(ar[i] > ar[j]) {
            temp[k++] = ar[j++];
            count+= mid-i;
        }
    }
    while(i<mid) {
        temp[k++] = ar[i++];
    }
    while(j<=hi) {
        temp[k++] = ar[j++];
    }
    while(lo<=hi) {
        ar[lo] = temp[lo];
        lo++;
    }
    return count;
}

long int  countInversions(int ar[], int lo, int hi)
{        
    long int inversions = 0;
    cout<<"lo"<<lo <<"hi"<<hi<<endl;
    if(lo < hi) {
        int mid = (hi-lo)/2+lo;
        inversions+= countInversions(ar, lo, mid);
        inversions+= countInversions(ar, mid+1, hi);
        inversions+= merge(ar, lo,mid +1,hi);

    }
    return inversions;
}
   
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    freopen("input.txt","r",stdin); 
    int t, n;
    cin>>t;
    cout<<"Input read t: " <<t<<endl;
    while(t-- > 0) {
        cin>>n;
        cout<<"Input read n: " <<n<<endl;
        int arr[n];    
        for(int i = 0; i<n; i++) {
            cin>>arr[i];
        //    cout<<"InputRead: i"<<arr[i]<<endl;
        }
        long int shift = countInversions(arr, 0, n-1);
        cout<<shift<<endl;
    }
    return 0;
}
