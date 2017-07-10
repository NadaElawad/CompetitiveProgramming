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

const double EPS = 1e-9;

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
int dcmp(double d, double e){
    return (d>e)-(d<-e);
}
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical
    
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;  //e.g ab is ray, cd is segment ... change to whatever
    return true;
}
// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
// may be see https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
pair<double, point> findCircle(point a, point b, point c) {
    //create median, vector, its prependicular
    point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
    point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
    point end1 = m1+pv1, end2 = m2+pv2, center;
    intersectSegments(m1, end1, m2, end2, center);
    return make_pair( length(a-center), center );
}



// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C),
    c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;
    
    vector<point> v;
    if( dcmp(f, 0) >= 0) {
        if( dcmp(f, 0) == 0)	f = 0;
        double t1 =(-b + sqrt(f))/(2*a);
        double t2 =(-b - sqrt(f))/(2*a);
        v.push_back( p0 + t1*(p1-p0) );
        if( dcmp(f, 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}

bool intersectCircleCircle(point c1, double r1, point c2, double r2) {
    double dis = (c1.real() - c2.real())*(c1.real() - c2.real())+(c1.imag() - c2.imag())*(c1.imag() - c2.imag());
    if(dis <= (r2+r1)*(r2+r1) && (r2-r1)*(r2-r1) <= dis) return true;
    return false;
}

const int MAX = 100000+9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs;	// ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);		rs = 0;
void MEC() {
    if(ps == 0 && rs == 2) {
        cen = (r[0]+r[1])/2.0;
        rad = length(r[0]-cen);
    }
    else if(rs == 3) {
        pair<double, point> p = findCircle(r[0], r[1], r[2]);
        cen = p.second;
        rad = p.first;
    }
    else if(ps == 0) {
        cen = r[0];	// sometime be garbage, but will not affect
        rad = 0;
    }
    else {
        ps--;
        MEC();
        
        if(length(pnts[ps]-cen) > rad) {
            r[rs++] = pnts[ps];
            MEC();
            rs--;
        }
        
        ps++;
    }
}
bool vis[200];
vector<pair<point, double> > vec;
int ans;
void f(int idx){
    vis[idx]=1;
    for(int i=0; i<vec.size(); i++){
        if(!vis[i] && intersectCircleCircle(vec[i].first, vec[i].second, vec[idx].first, vec[idx].second)){
            ans++;
            f(i);
        }
    }
}
int main(){
    int n;
    while(cin>>n && n!=-1){
        vec.clear();
        for(int i=0; i<n; i++){
            double x,y,c;
            cin>>x>>y>>c;
            vec.push_back({point(x,y),c});
        }
        int finalAns=0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans=1;
                f(i);
                finalAns=max(ans, finalAns);
            }
        }
        if(finalAns!=1)
            cout<<"The largest component contains "<<finalAns<<" rings."<<endl;
        else
            cout<<"The largest component contains "<<finalAns<<" ring."<<endl;
    }
}
