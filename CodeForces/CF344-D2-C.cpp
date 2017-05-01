/*
	Author: Nada Alaa
    
    Idea:
    - Using Calking-Wilf tree idea to recursively get the parent of each rational while adding 1 step for each backward operation
    - Since input is too large the problem must be reduced to gcd 
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
#define pi 3.14159265359
using namespace std;
vector<ll> fib;
ll f(ll a, ll b){
    if(!a||!b) return 0;
    if(a>=b) return f(b,a%b)+a/b;
    if(b>a) return f(a,b%a)+b/a;
    return 0;
}
int main(){
    ll a, b;
    cin>>a>>b;
    cout<<f(a,b)<<endl;
}
