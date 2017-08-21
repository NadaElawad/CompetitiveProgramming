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
using namespace std;
typedef long long ll;
bool composite[1000009];
vector<ll> prms;
void sieve(){
    composite[0] = composite[1] = 1;
    for(ll i = 2; i <= 1e6; i++){
        if(!composite[i]){
            prms.push_back(i);
            for(ll j = i*i; j <= 1e6; j+=i){
                composite[j] = 1;
            }
        }
    }
}
int main(){
    sieve();
    int t, tc = 1;
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        bool vis[1000009] = {0};
        vector<ll> ans;
        for(int i = 0; i < n; i++){
            ll in; scanf("%lld", &in);
            for(int j = 0; j < prms.size() && in != 1; j++){
                if(in%prms[j] == 0 && !vis[prms[j]]){
                    ans.push_back(prms[j]);
                    vis[prms[j]] = 1;
                }
                while(in%prms[j] == 0) in/=prms[j];
            }
            if(in > 1) ans.push_back(in);
        }
        int sz = 0;
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            if(i && ans[i] == ans[i-1]) continue;
            sz++;
        }
        printf("Case #%d: %d\n", tc++, sz);
        for(int i = 0; i < ans.size(); i++){
            if(i && ans[i] == ans[i-1]) continue;
            printf("%lld\n", ans[i]);
        }
    }
}