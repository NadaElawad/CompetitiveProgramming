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
    cin>>t;
    while(t--){
        int x, y; cin>>x>>y;
        int x1, y1, x2, y2;
        double dis = 0;
        cin.ignore();
        string s;
        while (getline(cin, s) && s.size()) {
            stringstream ss(s);
            ss >> x1 >> y1 >> x2 >> y2;
            dis += 2*sqrt((double)((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
        }
        int time = (dis*60/20000)+0.5;
        int hr = time/60, min = time%60;
        cout<<hr<<":";
        if(min<10) cout<<"0"<<min<<endl;
        else cout<<min<<endl;
        if(t) cout<<endl;
    }
}