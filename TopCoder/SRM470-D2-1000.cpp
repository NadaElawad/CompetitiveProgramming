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
using namespace std;


class ActivateGame {
public:
    vector<string> grid;
    int vis[51][51];
    int getvalue(int i, int j){
        if(isdigit(grid[i][j])) return grid[i][j] - '0';
        if(islower(grid[i][j])) return grid[i][j] - 'a' + 10;
        return grid[i][j] - 'A' + 36;
    }
    int getscore(int i, int j, int i1, int j1){
        return abs(getvalue(i, j) - getvalue(i1, j1));
    }
    bool valid(int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    int findMaxScore(vector <string> g) {
        grid = g;
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        priority_queue<pair<int, pair<int, int> > > qee;
        qee.push({0, {0, 0}});
        while(qee.size()){
            int i = qee.top().second.first, j = qee.top().second.second;
            int cost = qee.top().first;
            qee.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            ans += cost;
            if(valid(i - 1, j)) qee.push({getscore(i, j, i - 1, j), {i - 1, j}});
            if(valid(i + 1, j)) qee.push({getscore(i, j, i + 1, j), {i + 1, j}});
            if(valid(i, j - 1)) qee.push({getscore(i, j, i, j - 1), {i, j - 1}});
            if(valid(i, j + 1)) qee.push({getscore(i, j, i, j + 1), {i, j + 1}});
        }
        return ans;
    }
};