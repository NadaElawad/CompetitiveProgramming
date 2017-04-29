/*
	Author: Nada Alaa
	
	Idea:
    - Build a dependency adjacency matrix in order to apply topological sorting
 
 */

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
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;
int vis[110];
int n, m;
vector<int> vec[110];
vector<int> ordered;
void f(int node){
    vis[node]=1;
    for(int i=0; i<vec[node].size(); i++)
        if(!vis[vec[node][i]])
            f(vec[node][i]);
    ordered.push_back(node);
}
int main(){
    while(cin>>n>>m && n){
        ordered.clear();
        for(int i=1; i<=n; i++) vec[i].clear();
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            vec[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++){
            if(!vis[i])
                f(i);
        }
        for(int i=0; i<ordered.size(); i++){
            if(i) cout<<" ";
            cout<<ordered[i];
        }
        cout<<endl;
    }
}