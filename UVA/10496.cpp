/*
	Author: Nada Alaa
	
	Idea:
    - I try going to all cells in every order until I collect all beepers, and I take the minimum of all these solutions
    - Manhatten distance it used since I only move in four directions
 
 */

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
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;
int sx, sy, x, y, m, mat[24][24];
int Manhatten(int x1, int y1, int x2, int y2){
    return abs(x2-x1) + abs(y2-y1);
}
int f(int i, int j, int count){
    if(!count) return Manhatten(i, j, x, y);
    int ans = 1e9;
    for(int k = 1; k <= sx; k++){
        for(int l = 1; l <= sy; l++){
            if(mat[k][l]){
                mat[k][l] = 0;
                ans = min(ans, f(k, l, count-1)+Manhatten(i, j, k, l));
                mat[k][l] = 1;
            }
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(mat, 0, sizeof(mat));
        scanf("%d %d %d %d %d", &sx, &sy, &x, &y, &m);
        int idx=1;
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            mat[a][b] = idx++;
        }
        printf("The shortest path has length %d\n", f(x,y,m));
    }
}