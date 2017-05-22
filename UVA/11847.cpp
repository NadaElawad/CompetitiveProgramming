/*
    Author: Nada Alaa
    Idea:
        -Based on pure observation, tracing outputs for the first 16 numbers the answer is always the number of bit needed to generate this number.
*/
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
#define ll long long
using namespace std;
int main(){
    int n;
    while(cin>>n && n){
        cout<<(int)(log(n)/log(2))<<endl;
    }
}