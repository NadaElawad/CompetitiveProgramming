/*
	Author: Nada Alaa
	
	Idea:
    - I start by having an initial set of numbers that sum up to <= X
    - Iteratively incrementing each element of the set from left to right in order to keep the condition of them being in ascending order
 
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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int idx=2, sum=0;
        vector<int> par;
        while(sum+idx<=n){
            sum+=idx;
            par.push_back(idx++);
        }
        idx=(int)par.size()-1;
        while(sum<n){
            par[idx]++;
            idx=(idx-1+par.size())%(int)par.size();
            sum++;
        }
        for(int i=0; i<par.size(); i++){
            if(i) printf(" ");
            printf("%d",par[i]);
        }
        if(t) printf("\n");
        printf("\n");
    }
}