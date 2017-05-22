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
const double PI = acos(-1.0);
const double EPS = 1e-9;
//distance from point p2 to segment p0-p1
point distToSegment( point p0, point p1, point p2 ) {
    double d1, d2;
    point v1 = p1-p0, v2 = p2-p0;
    if( (d1 = dp(v1, v2) ) <= 0)	return p0;
    if( (d2 = dp(v1, v1) ) <= d1)	return p1;
    double t = d1/d2;
    return (p0 + v1*t);
}
bool intersectSegments(point a, point b, point c, point d) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parallel || identical
    
    double t1 = d2 / d1, t2 = d3 / d1;
    //intersect = a + (b - a) * t1;
    
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
        return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    while (n--) {
        long long xs, ys, xe, ye, x1, y1, x2, y2;
        cin>>xs>>ys>>xe>>ye;
        cin>>x1>>y1>>x2>>y2;
        
        if(x1>x2) swap(x1, x2);
        if(y2>y1) swap(y2, y1);
        
        bool ans = intersectSegments(point(xs, ys), point(xe, ye), point(x1, y1), point(x2, y1));
        ans |= intersectSegments(point(xs, ys), point(xe, ye), point(x2, y1), point(x2, y2));
        ans |= intersectSegments(point(xs, ys), point(xe, ye), point(x2, y2), point(x1, y2));
        ans |= intersectSegments(point(xs, ys), point(xe, ye), point(x1, y2), point(x1, y1));
        ans |= (xs>=x1 && xs<=x2 && xe>=x1 && xe<=x2 && ys>=y2 && ys<=y1 && ye>=y2 && ye<=y1);
        
        if(ans) cout<<"T"<<endl;
        else cout<<"F"<<endl;
    }
}