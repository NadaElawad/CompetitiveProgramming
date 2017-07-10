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
#include <complex>
#define ll long long
using namespace std;
ll gcd(ll a, ll b){
    if(!a) return b;
    return gcd(b%a, a);
}
int main(){
    int n;
    while(cin>>n && n!=-1){
        ll a, b, af, bf;
        cin>>af>>bf;
        for(int i=1; i<n-1; i++){
            cin>>a>>b;
            af*=a;
            bf*=b;
        }
        cout<<af/gcd(af,bf)<<" "<<bf/gcd(af,bf)<<endl;
    }
}