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
bool nprm[10009];
vector<int> prms;
void sieve(){
    nprm[0]=nprm[1]=1;
    for(int i=2; i<=10000; i++){
        if(!nprm[i]){
            prms.push_back(i);
            for (int j=i*i; j<=10000; j+=i) {
                nprm[j]=1;
            }
        }
    }
}
int m,a,b;
bool check(int p, int q){
    return a*prms[q]<=prms[p]*b && prms[p]*prms[q]<=m;
}
int bs(int l, int h, int p){
    int q=(l+h)/2;
    if(h<l) return -1;
    if(check(p,q) && !check(p,q+1)) return q;
    else if(check(p,q)) return bs(q+1, h, p);
    else return bs(l, q-1, p);
}
int main(){
    sieve();
    while(cin>>m>>a>>b && m && a && b){
        int maxi=0, myp=0, myq=0;
        for(int i=0; i<prms.size(); i++){
            int q=bs(i, (int)(prms.size()-1), i);
            if(q!=-1 && prms[q]*prms[i] > maxi){
                maxi=prms[q]*prms[i];
                myp = prms[i];
                myq = prms[q];
            }
        }
        cout<<myp<<" "<<myq<<endl;
    }
}