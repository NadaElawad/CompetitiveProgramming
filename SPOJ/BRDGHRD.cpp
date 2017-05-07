
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
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    
    return r;
}
int LongestIncreasingSubsequenceLength(std::vector<pair<int,int> > &v) {
    if (v.size() == 0)
        return 0;
    
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
    
    tail[0] = v[0].second;
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i].second < tail[0])
            // new smallest value
            tail[0] = v[i].second;
        else if (v[i].second > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i].second;
        else
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length-1, v[i].second)] = v[i].second;
    }
    
    return length;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<pair<int, int> > l(n);
        for(int i=0; i<n; i++) cin>>l[i].first;
        for(int i=0; i<n; i++) cin>>l[i].second;
        sort(l.begin(), l.end());
        
        //http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
        cout<<LongestIncreasingSubsequenceLength(l)<<endl;
    }
}
