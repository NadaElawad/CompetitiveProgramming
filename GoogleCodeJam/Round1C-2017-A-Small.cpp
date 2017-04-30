/*
	Author: Nada Alaa 
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
int n,k;
vector<pair<int,int> > vec;
double area(int i){
    if(i==-1) return 0;
    int radius=vec[i].first;
    return pi*radius*radius;
}
double hei(int i){
    return 2*pi*vec[i].first*vec[i].second;
}
double f(int idx, int count, int prev){
    if(count==k) return area(prev);
    if(idx==n) return -1e9;
    double ans=0;
    ans = max(ans, f(idx+1, count, prev));
    ans = max(ans, f(idx+1, count+1, idx)+hei(idx)+(area(prev)<=0?area(idx):area(prev))-area(idx));
    return ans;
}
int main(){
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>k;
        vec.clear();
        for(int i=0; i<n; i++){
            ll r,h;
            cin>>r>>h;
            vec.push_back({r,h});
        }
        sort(vec.rbegin(),vec.rend());
        int arr[20];
        for(int i=n-k; i<n; i++) arr[i]=1;
        cout<<fixed<<setprecision(7)<<"Case #"<<tc<<": "<<f(0,0,-1)<<endl;
    }
}
