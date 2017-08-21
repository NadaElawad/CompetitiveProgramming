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
int graph[16][16];
int n, dp[1<<16][16];
string common[16][16];
vector<string> s;
int conn(string s, string t){
    if(s.find(t) != string::npos) return 0;
    int ret=0;
    for (int i=0; i<=min(s.size(), t.size()); i++) {
        if (s.substr(s.size()-i)==t.substr(0, i)) {
            ret=i;
        }
    }
    return (int)t.size()-ret;
}
int dfs(int idx, int mask){
    if(mask==((1<<n)-1)) return 0;
    if(dp[mask][idx]!=-1) return dp[mask][idx];
    int ans=1e9;
    for(int i=0; i<n; i++){
        if(!(mask&(1<<i))){
            ans = min(ans, graph[idx][i]+dfs(i, mask|(1<<i)));
        }
    }
    return dp[mask][idx]=ans;
}
void build(int idx, int mask){
    if(mask==((1<<n)-1)) return;
    string cur="Z";
    int nxt=-1;
    for(int i=0; i<n; i++){
        int tmp = dfs(i,  mask|(1<<i)) + graph[idx][i];
        if(!((1<<i)&mask) &&  tmp == dp[mask][idx] && cur > common[idx][i]){
            cur=common[idx][i];
            nxt=i;
        }
    }
    cout<<common[idx][nxt];
    build(nxt, mask | (1 << nxt));
}
int main(){
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n;
        s.resize(n);
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        sort(s.begin(), s.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int w = conn(s[i], s[j]);
                if(w==0) {
                    s.erase(s.begin()+j);
                    n--;
                    i = -1; break;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int w = conn(s[i], s[j]);
                graph[i][j]=w;
                common[i][j]=s[j].substr(s[j].size()-w);
            }
        }
        int ans=1e9, idx=0;
        for(int i=0; i<n; i++){
            if(ans > dfs(i, 1<<i) + (int)s[i].size() || (ans == dfs(i, 1<<i) + (int)s[i].size() && s[idx] > s[i])){
                ans = dfs(i, 1<<i) + (int)s[i].size();
                idx = i;
            }
        }
        cout<<"Scenario #"<<tc<<":"<<endl;
        cout<<s[idx];
        build(idx, (1<<idx));
        cout<<endl<<endl;
    }
}
