/*
	Author: Nada Alaa
 
    Idea:
    - Given that the maximum element in A would be R (R<=15000), then the ORing between elements in A will not exceed 2^14 (16384) and so is their summation.
    - ORing numbers that don't have any common 1-bits will result in a possible solution since it would be the same as adding them
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
#define ll long long
using namespace std;


class YetAnotherORProblem2 {
public:
    int R_, mod = 1e9+9;
    int dp[12][17000];
    int f(int idx, int sum){
        if(!idx) return 1;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int ans = 0;
        for(int i=0; i<=R_; i++){
            if(!(sum&i))
                ans=(ans+f(idx-1, sum|i))%mod;
        }
        return dp[idx][sum]=(int)ans;
    }
    int countSequences(int N, int R) {
        R_ = R;
        memset(dp, -1, sizeof(dp));
        return f(N, 0);
    }
};
