/*
	Author: Nada Alaa
	
	Idea:
    - Print all combinations between the divisors, straight forward
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
    int p, q;
    scanf("%d %d", &p, &q);
    vector<int> p_div, q_div;
    for(int i=1; i<=q; i++){
        if(q%i==0) q_div.push_back(i);
    }
    for(int i=1; i<=p; i++){
        if(p%i==0) {
            for(int j=0; j<q_div.size(); j++){
                printf("%d %d\n", i, q_div[j]);
            }
        }
    }
}