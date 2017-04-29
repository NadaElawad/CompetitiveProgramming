/*
	Author: Nada Alaa
	
	Idea:
    - Count the occurences of each vote and get its ratio of the total votes in percentage
 
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
    int n, m, arr[100023]={0};
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x; cin>>x;
        arr[x]++;
    }
    for(int i=1; i<=n; i++){
        cout<<fixed<<setprecision(2)<<(arr[i]*100.0)/m<<"%"<<endl;
    }
}