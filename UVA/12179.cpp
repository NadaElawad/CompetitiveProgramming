#include <iostream>
#include <time.h>
#include <vector>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <assert.h>
#include <sstream>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long ll;
int r;
double dp[10003][104];
double f(int sum, int step){
    if(!step && sum >= 0) return 1;
    if(sum < 0) return 0;
    if(dp[sum][step]!=-1) return dp[sum][step];
    double ans = 0;
    for(int i=1; i<=r; i++){
        ans+=f(sum-i, step-1);
    }
    return dp[sum][step]=ans/r;
}
int main(){
    int t; scanf("%d", &t);
    int tc = 1;
    while(t--){
        int c, n; scanf("%d %d", &n, &r);
        char s[102][102];
        int mat[103][103];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = 1e9;
            }
        }
        for(int i=0; i<n; i++) scanf(" %s", s[i]);
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[i][j]=='Y') mat[j][i] = mat[i][j] = 1;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        scanf("%d", &c);
        printf("Case %d\n", tc++);
        for(int i=0; i<10001; i++){
            for(int j=0; j<101; j++) dp[i][j] = -1;
        }
        while(c--){
            int a, b, m;
            scanf("%d %d %d", &a, &b, &m);
            double tmp = f(m, mat[a-1][b-1]);
            printf("%.6f\n", tmp);
        }
        printf("\n");
    }
}
