#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;
bool isgreater(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first.first>b.first.first && a.first.second>b.first.second) return 1;
    if(a.first.first>b.first.first && a.second>b.second) return 1;
    if(a.first.second>b.first.second && a.second>b.second) return 1;
    return 0;
}
int main(){
    int n; cin>>n;
    string s[222];
    vector<pair<pair<int, int>, int> > vec(n);
    for(int i=0; i<n; i++){
        cin>>s[i]>>vec[i].first.first>>vec[i].first.second>>vec[i].second;
    }
    int beat[222][222]={0};
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(isgreater(vec[i], vec[j])) beat[i][j] = 1;
            else beat[j][i] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                beat[j][k] |= beat[j][i]&beat[i][k];
            }
        }
    }
    for(int i=0; i<n; i++){
        int tmp=0;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            tmp+=beat[i][j];
        }
        if(tmp==n-1) cout<<s[i]<<endl;
    }
}