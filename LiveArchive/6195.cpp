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
#include <complex>
#define ll long long
using namespace std;
int vis[2000];
vector<vector<int> > vec;
bool IsCyclic(int node){
    bool ans = 0;
    if(vis[node]==1) return true;
    vis[node] = 1;
    for(int i=0; i<vec[node].size(); i++){
        if(vis[vec[node][i]] != 2)
            ans |= IsCyclic(vec[node][i]);
    }
    vis[node] = 2;
    return ans;
}
int main(){
    int n, m;
    while(cin>>n>>m && n && m){
        vec.clear();
        vec.resize(n+1);
        int count[2000]={0};
        vector<vector<int> > revVec(n+1);
        for(int i=0; i<m; i++){
            int u, v; cin>>u>>v;
            vec[v].push_back(u);
            revVec[u].push_back(v);
            count[v]++;
        }
        int zero=0, ans=1;
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                zero|=IsCyclic(i);
            }
        }
        if(zero) cout<<0<<endl;
        else{
            queue<int> topo;
            for(int i=1; i<=n; i++){
                if(!(vec[i].size())) topo.push(i);
            }
            for(int i=0; i<n; i++){
                if(topo.size()>1) ans = 2;
                int cur = topo.front();
                topo.pop();
                for(int j=0; j<revVec[cur].size(); j++){
                    count[revVec[cur][j]]--;
                    if(count[revVec[cur][j]]==0) topo.push(revVec[cur][j]);
                }
            }
            if(ans==1) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
}