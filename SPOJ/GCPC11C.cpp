#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int count[11234] = {0};
        int n, h; scanf("%d %d", &n, &h);
        vector<int> vec[11234], revec[11234], out;
        for(int i=0; i<h; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            vec[b].push_back(a);
            revec[a].push_back(b);
            count[b]++;
        }
        int ans = 1;
        queue<int> topo;
        for(int i=1; i<=n; i++){
            if(!(vec[i].size())) topo.push(i);
        }
        for(int i=0; i<n; i++){
            if(topo.size() > 1) ans = 2;
            else if(!topo.size()){
                ans = 0;
                break;
            }
            int cur = topo.front();
            topo.pop();
            out.push_back(cur);
            for(int j=0; j<revec[cur].size(); j++){
                count[revec[cur][j]]--;
                if(count[revec[cur][j]]==0) topo.push(revec[cur][j]);
            }
        }
        if(ans == 0) printf("recheck hints\n");
        else if(ans == 2) printf("missing hints\n");
        else{
            for(int i=0; i<n; i++) printf("%d ", out[i]);
            printf("\n");
        }
    }
}