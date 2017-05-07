/*
    Author: Nada Alaa
    Idea:
        - Each chromosome has number of features, X has only one node with degree=4, Y has only one node with degree=3, I doesn't have any degree greater than 2.
        - Counting each node's degree and applying a rule for each chromosome with paying attention to corner case of having degrees>4 and nodes with no degree at all
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define ll long long
using namespace std;
int main(){
    int n, tc=1;
    cin>>n;
    while(n--){
        int nodes, edges;
        cin>>nodes>>edges;
        vector<vector<int> > vec(nodes+1);
        for(int i=0; i<edges; i++){
            int u, v; cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        cout<<"Case "<<tc++<<": ";
        int count[5]={0};
        bool flag=0;
        for(int i=1; i<=nodes; i++){
            if(vec[i].size()>4||vec[i].size()==0){cout<<"NotValid\n"; flag=1; break;}
            count[vec[i].size()]++;
        }
        if(flag) continue;
        if(count[4]==1&&!count[3]&&count[1]==4) cout<<"X\n";
        else if(count[3]==1&&!count[4]&&count[1]==3) cout<<"Y\n";
        else if(!count[3]&&!count[4]&&count[1]==2) cout<<"I\n";
        else cout<<"NotValid\n";
    }
}