#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getNumber(string s, int i, int j) {
//	cout<<"i" <<i<<" j"<<j<<endl;
    int temp = 0;
    while(i<=j) {
        temp*=10;
        temp+=(int)s[i++] - '0';
    }
    return temp;
}
vector < int > frequency(string s) {
    vector<int> myVector(26);

    int len = s.length();
    for(int i = len-1; i>=0;) {
        int frequency = 1;
      //  cout<<"Char iteration "<<s[i]<<endl;
        if(s[i] == ')') {
            int reduceIdxBy = 0;
            for(int j= i;; j--) {
            	reduceIdxBy++;
                if(s[j] == '(') {
                    frequency = getNumber(s, j+1, i -1);
                    break;
                }
            }
            i-=reduceIdxBy;
      //      cout<<"ReduceBy "<<reduceIdxBy<<endl;
        }
        int number = 0;
        if(s[i]=='#') {
        //	cout<<"Substr "<<s.substr( i-2, 2);
            number  = getNumber(s, i-2, i-1);
           i-=3;
           myVector[number-1] = myVector[number-1] + frequency;
        } else {
            number  = getNumber(s, i, i);
           // 	cout<<"Substr "<<s.substr( i, 1);
           // cout<<"Number" <<number<<" Frequency"<<frequency<<endl;
            i-=1;
            myVector[number-1] = myVector[number-1] + frequency;
        }
    }
    return myVector;
}

int main() {
  //  ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;
    string _s;
    getline(cin, _s);
    
    res = frequency(_s);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
   // fout.close();
    return 0;
}

