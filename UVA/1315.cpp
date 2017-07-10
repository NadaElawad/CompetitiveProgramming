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
        int n, tmp=1, ans=0; cin>>n;
        while(n>2){
            ans+=2*tmp;
            n-=2;
            if(n==1){
                ans-=tmp;
                break;
            }
            tmp++;
        }
        cout<<ans<<endl;
    }
}