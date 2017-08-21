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
#include <unordered_map>
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
ll x[110], y[110], sm[110], sv[110], pm[110], pv[110];
int n, m;
bool check(ll meals){
    ll money = m;
    for(int i=0; i<n; i++){
        ll mini = 1e18;
        for(int j=0; j<=1e4; j++){
            ll tmp = max(meals*x[i]-y[i]-sm[i]*j, 0ll);
            ll k = tmp/sv[i] + (tmp%sv[i]!=0);
            mini = min(mini, j*pm[i]+k*pv[i]);
        }
        money -= mini;
        if(money < 0) return false;
    }
    return money >= 0;
}
ll bs(ll l, ll h){
    ll mid = (l+h)/2;
    bool ismid = check(mid);
    if(ismid && !check(mid+1)) return mid;
    if(ismid) return bs(mid+1, h);
    return bs(l, mid-1);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%lld %lld %lld %lld %lld %lld", &x[i], &y[i], &sm[i], &pm[i], &sv[i], &pv[i]);
    }
    printf("%lld\n", bs(0, 1e11));
}