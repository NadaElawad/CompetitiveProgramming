/*
	Author: Nada Alaa
	
	Idea:
    - Knapsack solution, I try different sets of the first 11 factorials (since 11! > 1e7)
    - I return a mask for the chosen set and compare this mask for both x and y by taking the AND bitwise operation between the two masks in order to be sure there's no common element in the factorial sets
    - Complexity is O(1) since it is independent of the input
 
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
ll fact[12];
ll factorial(int n){
    ll ret = n;
    while(--n){
        ret*=n;
    }
    return ret;
}
int f(ll sum, int i, int mask){
    if(!sum) return mask;
    if(sum < 0 || i > 11) return -1;
    return max(f(sum-fact[i], i+1, mask|(1<<(i-1))),f(sum, i+1, mask));
}
int main(){
    ll x, y;
    while(cin>>x>>y && x && y){
        for(int i=1; i<=11; i++){
            fact[i]=factorial(i);
        }
        int mask1 = f(x,1,0);
        int mask2 = f(y,1,0);
        if(mask1!=-1 && mask2!=-1 && !(mask1&mask2)) printf("Yes\n");
        else printf("No\n");
    }
}