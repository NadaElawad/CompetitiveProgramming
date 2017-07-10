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
    while(cin>>t && t){
        vector<pair<int,int> > vec(t);
        for(int i=0; i<t; i++){
            cin>>vec[i].first>>vec[i].second;
        }
        int x = vec[t/2].first, y = vec[t/2].second;
        int ollie = 0, stan = 0;
        for(int i=0; i<t; i++){
            ollie+=vec[i].first>x && vec[i].second>y;
            ollie+=vec[i].first<x && vec[i].second<y;
            stan+=vec[i].first>x && vec[i].second<y;
            stan+=vec[i].first<x && vec[i].second>y;
        }
        cout<<ollie<<" "<<stan<<endl;
    }
}
