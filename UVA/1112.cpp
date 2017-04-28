/*
	Author: Nada Alaa
	
	Idea:
    - I basicly only need the shortest paths from all nodes to the exit node, then I check if this shortest path <= timer
    - Applying Floyd would be the easiest to implement since N<=100 which means complexity is within reasonable range
    
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
using namespace std;
int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n, e, t, m, graph[110][110];
        for(int i=0; i<110; i++){
            for(int j=0; j<110; j++){
                graph[i][j]=1e9;
            }
        }
        scanf("%d %d %d %d", &n, &e, &t, &m);
        for(int i = 0; i < m; i++){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            graph[a][b]=w;
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    graph[i][j]=min(graph[i][k]+graph[k][j], graph[i][j]);
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(i!=e && graph[i][e]<=t) ans++;
        }
        if(tc) printf("%d\n\n", ans+1);
        else printf("%d\n", ans+1);
    }
}
