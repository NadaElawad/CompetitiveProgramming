/*
	Author: Nada Alaa
	
	Idea:
    - Between N+1 consecutive volumes there are 2*N covers and N+1 sheets in case of start is greater than end and N sheets in case of end is greater than start
    - Getting the absolute distance between the start and end volumes gives me N
 
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
    int t1,t2,s,d;
    scanf("%d %d %d %d",&t1,&t2,&s,&d);
    cout<<abs(s-d)*2*t2+(abs(s-d)+(s>d?1:-1))*t1<<endl;
}