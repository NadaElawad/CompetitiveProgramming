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
using namespace std;
const double PI = acos(-1.0);

const double EPS = 1e-9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
double distToSegment(pair<int,int> p, pair<int,int> left, pair<int,int> right) {
    point p0(p.first, p.second);
    point p1(left.first, left.second);
    point p2(right.first, right.second);
    double d1, d2;
    point v1 = p1-p0, v2 = p2-p0;
    if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
    if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
    double t = d1/d2;
    return length(p2 - (p0 + v1*t) );
}

int ccw(point a, point b, point c) {
    point v1(b - a), v2(c - a);
    double t = cp(v1, v2);
    
    if (t > +EPS)
        return +1;
    if (t < -EPS)
        return -1;
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
        return -1;
    if (norm(v1) < norm(v2) - EPS)
        return +1;
    return 0;
}

bool valid(pair<int,int> left, pair<int,int> right, pair<int,int> p){
    return p.first >= left.first && p.first <= right.first
    && ccw(point(left.first, left.second), point(right.first, right.second), point(p.first, p.second)) == 1;
}
int main(){
    int t;
    bool flag = 0;
    cin>>t;
    while(t--){
        if(flag) cout<<endl;
        flag = 1;
        int n, m; cin>>n;
        vector<pair<pair<int, int>, pair<int, int> > > vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i].first.first>>vec[i].first.second>>vec[i].second.first>>vec[i].second.second;
            if(vec[i].first>vec[i].second) swap(vec[i].first, vec[i].second);
        }
        cin>>m;
        while(m--){
            pair<int, int> p;
            cin>>p.first>>p.second;
            while(true){
                double minDis = 1e9;
                int idx = -1;
                for(int i=0; i<vec.size(); i++){
                    if(valid(vec[i].first, vec[i].second, p)){
                        double curDis = distToSegment(vec[i].first, vec[i].second, p);
                        if(curDis < minDis){
                            minDis = curDis;
                            idx = i;
                        }
                    }
                }
                if(idx == -1){
                    break;
                }else{
                    if(vec[idx].first.second > vec[idx].second.second) p = vec[idx].second;
                    else p = vec[idx].first;
                }
            }
            cout<<p.first<<endl;
        }
    }
}
