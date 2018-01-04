#include <bits/stdc++.h>

using namespace std;

bool myFunc(string a, string b) {
    if(a.length() == b.length()) {
        return (a<b);
    }
    return a.length() <= b.length();
}
int main(){
    int n;
    freopen("input.txt","r",stdin);
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    sort(unsorted.begin(), unsorted.end(), myFunc);
    for(int unsorted_i = 0; unsorted_i <n; unsorted_i++) {
        cout<<unsorted[unsorted_i]<<"\n";
    }
    // your code goes here
    return 0;
}
