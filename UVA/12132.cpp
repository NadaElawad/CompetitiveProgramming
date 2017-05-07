/*
    Author: Nada Alaa
    Idea:
        - Problem is simple simulation. Keeping track of each car's floor and position, and starting from a the first position on the first floor and visiting all cars in order.
        - For each car, taking the minimum between reaching it from a clockwise and anti-clockwise direction give the optimal answer to this car with addition to time require to reach the floor which is independent of the position of the car in this particular floor
 */
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
    int n;
    cin>>n;
    while(n--){
        int h,l;
        cin>>h>>l;
        vector<vector<int> > vec(h);
        int f[2505], p[2505], maxi=0;;
        for(int i=0; i<h; i++){
            for(int j=0; j<l; j++){
                int tmp; cin>>tmp;
                vec[i].push_back(tmp);
                if(tmp!=-1){f[tmp]=i; p[tmp]=j; maxi=max(maxi, tmp);}
            }
        }
        int ans=0,curp[100]={0};
        for(int i=1; i<=maxi; i++){
            int cw=abs(curp[f[i]]-p[i]);
            int ccw=abs(l-abs(p[i]-curp[f[i]]));
            ans+=2*10*(f[i])+min(cw,ccw)*5;
            curp[f[i]]=p[i];
        }
        cout<<ans<<endl;
    }
}