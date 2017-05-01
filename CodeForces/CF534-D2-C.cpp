/*
	Author: Nada Alaa
    
    Idea:
    - I define for each value a lower L and upper U bounds that this value must be within [L U]
    - After finding the range in which the value must be contained it is easy to get the range in which the value can not be contained using
        V - (U - L + 1)
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
int main(){
    ll a, b, sum=0, arr[212345];
    cin>>a>>b;
    for(int i=0; i<a; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0; i<a; i++){
        ll lower=max(-sum+arr[i]+b,1ll);
        ll upper=min(arr[i],b-a+1);
        cout<<arr[i]-upper+lower-1<<" ";
    }
    cout<<endl;
}
