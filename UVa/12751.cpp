/*
	Author: Nada Alaa
	
	Idea:
    - Print the difference between two summations
 
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
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        int n, x, k;
        cin>>n>>k>>x;
        cout<<"Case "<<tc<<": "<<(n*(n+1))/2-(k*(2*x+k-1))/2<<endl;
    }
}