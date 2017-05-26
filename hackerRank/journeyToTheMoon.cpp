#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#define SIZE 100002
using namespace std;
vector<int> visited(SIZE);
vector<vector<int> > pairs(SIZE);
long long nodes;
void DFS(int N, int node) {
    visited[node] = 1;
    vector<int>::iterator it;
    nodes++;
    for(it = pairs[node].begin();it!=pairs[node].end();it++) {
        if(visited[*it] == 0 ) {
            DFS(N, *it);
        }
    }
}
 
int main()
{ 
    int N, I;
    scanf("%d %d",&N, &I);
    
    for (int i = 0; i < I; ++i) {
        int a, b;
        scanf("%d %d", &a,&b);
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    int nodesSoFar = 0;
    long long preAns = 0, result = 0;
    
    for(int i = 0;i<N;i++) {
        if(visited[i] == 0) {
            nodes = 0;
            DFS(N, i);
            result += preAns + nodesSoFar*nodes;
            nodesSoFar += nodes;
        }
    }    
    /** Write code to compute the result using N,I,pairs **/
    
    
    cout << result << endl;
    return 0;
}

