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
#include <complex>
#define ll long long
using namespace std;
int main(){
    int n; cin>>n;
    vector<pair<pair<int,int>, int > > vec(n);
    for(int i=0; i<n; i++) {
        cin>>vec[i].first.first>>vec[i].first.second;
        vec[i].second = i+1;
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<n; i+=2){
        cout<<vec[i].second<<" "<<vec[i+1].second<<endl;;
    }
}