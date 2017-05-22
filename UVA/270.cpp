/*
	Author: Nada Alaa
	Idea:
		- Get the slope of each two pair of points and save it in a map as a pair representing the denominator and nominator (to avoid divison and precision errors)
		- Keep the maximum no. of points for all slopes as you go
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
#include <complex>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}
int main(){
    int t;
    cin>>t;
    string line;
    cin.ignore();
    cin.ignore();
    while(t--){
        int x, y;
        vector<pair<int,int> > vec;
        while(getline(cin,line)){
            if(line=="") break;
            sscanf(line.c_str(), "%d %d", &x, &y);
            vec.push_back({x, y});
        }
        int ans=0;
        for(int i=0; i<vec.size(); i++){
            map<pair<int,int>, int> mop;
            for(int j=i+1; j<vec.size(); j++){
                int gcd_ = gcd(vec[i].second-vec[j].second, vec[i].first-vec[j].first);
                x = (vec[i].first-vec[j].first)/(gcd_?gcd_:1);
                y = (vec[i].second-vec[j].second)/(gcd_?gcd_:1);
                ans=max(ans, ++mop[{y, x}]);
            }
        }
        cout<<ans+1<<endl;
        if(t) cout<<endl;
    }
}