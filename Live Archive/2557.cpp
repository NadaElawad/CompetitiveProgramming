/*
	Author: Nada Alaa
	
	Idea:
    - For a room to be unlocked it need to have odd number of divisors including 1 and itself, only a perfect square would have an odd number of divisors.
    - Number that have a perfect squares in range from 1 to N is all numbers from 1 to sqrt(N), so the answer is sqrt(N) 
 
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
        int n;
        scanf("%d", &n);
        int ans=(int)sqrt(n);
        printf("%d\n", ans);
    }
}