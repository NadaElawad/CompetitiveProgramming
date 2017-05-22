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
const double PI  = acos(-1.0);
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

//distance from point p2 to segment p0-p1
point distToSegment( point p0, point p1, point p2 ) {
    double d1, d2;
    point v1 = p1-p0, v2 = p2-p0;
    if( (d1 = dp(v1, v2) ) <= 0)	return p0;
    if( (d2 = dp(v1, v1) ) <= d1)	return p1;
    double t = d1/d2;
    return (p0 + v1*t);
}
int main(){
    double xm, ym;
    int n;
    while(cin>>xm>>ym){
        cin>>n;
        double x1, y1, x2, y2;
        cin>>x1>>y1;
        double xout = x1, yout = y1, mindist = 1e11;
        while(n--){
            cin>>x2>>y2;
            point p = distToSegment(point(x1, y1), point(x2, y2), point(xm, ym));
            double cur = length(point(xm, ym) - p);
            if(cur < mindist){
                mindist = cur;
                xout = p.real();
                yout = p.imag();
            }
            x1=x2; y1=y2;
        }
        cout<<fixed<<setprecision(4)<<xout<<endl<<yout<<endl;
    }
}