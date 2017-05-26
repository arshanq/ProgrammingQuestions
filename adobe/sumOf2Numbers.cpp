/* Write your custom/own functions here */
bool isSumPossible(vector< int > a , int N) {
    sort(a.begin(),a.end());
    int l=0,r=a.size()-1;
    while(l < r) {
        if(a[l] + a[r] == N) {
            return 1;
        }
        else if( (a[l] + a[r] ) < N) {
            l++;
        }
        else r--;
    }
    return 0;
}