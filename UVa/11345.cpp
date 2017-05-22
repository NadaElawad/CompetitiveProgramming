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
using namespace std;

int main(){
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++){
        int m; cin>>m;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        bool flag=0;
        cin>>x1>>y1>>x2>>y2;
        for(int i=1; i<m; i++){
            cin>>x3>>y3>>x4>>y4;
            x1 = max(x1,x3);
            y1 = max(y1,y3);
            
            x2 = min(x2,x4);
            y2 = min(y2,y4);
            
            if(x1>x2||y1>y2) flag=1;
        }
        if(flag) cout<<"Case "<<tc<<": "<<0<<endl;
        else cout<<"Case "<<tc<<": "<<(y2-y1)*(x2-x1)<<endl;
    }
}