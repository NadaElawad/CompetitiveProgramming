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
#define ll long long
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
        if(n%k==0){
            cout<<2*(n/k)<<endl;
        }else if(k>n){
            cout<<2<<endl;
        }else{
            cout<<(2*n+k-1)/k<<endl;
        }
}