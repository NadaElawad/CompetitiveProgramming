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
#include <complex>
#define ll long long
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    int tmp = (n-1)*m+(m-1);
    tmp%2? cout<<"[:=[first]\n":cout<<"[second]=:]\n";
}