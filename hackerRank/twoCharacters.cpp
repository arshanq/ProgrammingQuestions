#include <bits/stdc++.h>

using namespace std;
int getLen(char a, char b, string s) {
    int flag =-1, len = 0;
    for(int i = 0;i<s.length();i++) {
        if(s[i] == a) {
            if(flag > 0 && flag != (int)b) return -1;
            if(flag == (int)b 
              || flag < 0) {
                len++;
                flag = (int)a;
            }
        }else if(s[i] == b) {
            if(flag > 0 && flag != (int)a) return -1;
            if(flag == (int)a 
              || flag < 0) {
                len++;
                flag = (int)b;
            } 
        }
    }
    return len;
}

int maxLen(string s){
    int max = 0, len = 0;
    if(s.length() == 1) return 0;
    for(int i=0;i<26;i++) {
        for(int j=i+1;j<26;j++){
           // if(i!=j) {
                len = getLen('a' + i, 'a' + j, s);
                max = max > len? max: len;
           // }
        }
    }
    return max;
}



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = maxLen(s);
    cout << result << endl;
    return 0;
}
