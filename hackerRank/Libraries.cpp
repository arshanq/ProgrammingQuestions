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
#define SIZE 100001
using namespace std;
int visitedNodes[SIZE];
int nodes;
vector<int> vect[SIZE];

void clear() {
	for(int i = 0 ; i< SIZE;i++) {
		vect[i].clear();
		visitedNodes[i]= 0;
	}
}

void DFS(int i) {
	visitedNodes[i] = 1;
	nodes++;
	for(vector<int>::iterator it = vect[i].begin(); it!=vect[i].end();it++) {
		if(visitedNodes[*it] == 0) {
			DFS(*it);
		}
	}
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int x;
        int y;
        clear();
        cin >> n >> m >> x >> y;
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            vect[city_1].push_back(city_2);
            vect[city_2].push_back(city_1);
        }
        long long ans = 0;
        for(int i = 1; i<=n;i++) {
        	nodes = 0;
        	if(visitedNodes[i] == 0 ) {
        		ans += x; 
        		DFS(i);
        		if(x < y) {
        			ans += (nodes-1) * x;
        		}
        		else {
        			ans += (nodes-1) * y;
        		}
        	}
        }
        cout<<ans<<endl;

    }
    return 0;
}

