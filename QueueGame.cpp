#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    int X, N;
    cin>>N>>X;
    pair<int, int > maxPair, tempPair;
    maxPair.first = -1;
    maxPair.second = -1;
    queue<pair<int, int> > q;
    queue<pair<int, int> > tempQ;
    for(int i=0;i<N;i++) {
        int temp;
        cin>>temp;
        q.push(make_pair(temp, i));    
    }
    for(int iteration=0;iteration<X;iteration++) {
        maxPair.first = -1;
     //   cout<<"Q size"<<q.size()<<endl;
        for(int item = 0; item<X && q.size();item++) {
            tempPair = q.front();
            q.pop();
     //       cout<<"Temp pair "<<tempPair.first<<" init pos "<<tempPair.second<<endl;
            if(tempPair.first > maxPair.first) {
                maxPair.first = tempPair.first;
                maxPair.second = tempPair.second;
            }
            tempQ.push(tempPair);
        }
        int sz = tempQ.size();
        for(int item = 0; item < sz;item++) {
            tempPair = tempQ.front();
            tempQ.pop();
            if(tempPair.second != maxPair.second) {
                int ele = tempPair.first - 1;
                if(ele < 0) ele = 0;
                q.push(make_pair(ele, tempPair.second));
              //  cout<<"inserting element inti pos "<<tempPair.second<<endl;
            }
        }
        cout<<maxPair.second + 1<<" ";
        
    }
    return 0;
}
