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
    ll x,y;
    while(cin>>y>>x && (x||y)){
        if(y>x) cout<<fixed<<setprecision(6)<<(double)0<<endl;
        else cout<<fixed<<setprecision(6)<<(double)(x-y+1)/(x+1)<<endl;
    }
}