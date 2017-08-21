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
int vis[29][29], r, c;
pair<int, int> ans[30];
bool flag = 0;
bool valid(int x, int y){
    return x >= 1 && y >= 1 && x <= r && y <= c;
}
void f(int x, int y, int count){
    vis[x][y] = count;
    ans[count] = make_pair(x, y);
    if(count == r*c) {
        flag = 1;
        return;
    }
    if(!flag && valid(x-1, y-2) && !vis[x-1][y-2]){
        f(x-1, y-2, count+1);
    }
    if(!flag && valid(x+1, y-2) && !vis[x+1][y-2]){
        f(x+1, y-2, count+1);
    }
    if(!flag && valid(x-2, y-1) && !vis[x-2][y-1]){
        f(x-2, y-1, count+1);
    }
    if(!flag && valid(x+2, y-1) && !vis[x+2][y-1]){
        f(x+2, y-1, count+1);
    }
    if(!flag && valid(x-2, y+1) && !vis[x-2][y+1]){
        f(x-2, y+1, count+1);
    }
    if(!flag && valid(x+2, y+1) && !vis[x+2][y+1]){
        f(x+2, y+1, count+1);
    }
    if(!flag && valid(x-1, y+2) && !vis[x-1][y+2]){
        f(x-1, y+2, count+1);
    }
    if(!flag && valid(x+1, y+2) && !vis[x+1][y+2]){
        f(x+1, y+2, count+1);
    }
    vis[x][y] = 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>r>>c;
        flag = 0;
        for(int i=1; i<=c; i++){
            for(int j=1; j<=r; j++){
                if(!flag){
                    memset(vis, 0, sizeof(vis));
                    f(i, j, 1);
                }else{
                    i = j = 30;
                }
            }
        }
        if(!flag) cout<<-1<<endl;
        else{
            for(int i=1; i<=r*c; i++)
                cout<<char('A'+ans[i].second-1)<<ans[i].first;
            cout<<endl;
        }
    }
}
