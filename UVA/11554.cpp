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
    int t;
    ll arr[1000033]={0,1};
    for(int i=2; i<=1000000; i++){
        arr[i]=arr[i-2]+2;
    }
    for(int i=2; i<=1000000; i++){
        arr[i]+=arr[i-2];
    }
    for(int i=2; i<=1000000; i++){
        arr[i]+=arr[i-1];
    }
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", arr[n-3]);
    }
}