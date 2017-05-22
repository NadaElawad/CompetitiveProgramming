/*
	Author: Nada Alaa
	
	Idea:
    - No explicit idea, just followed the problem statement using string functionalities like erase and insert
 
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
bool findstr(string &s, string t, string sub){
    for(int i=0; i<=s.size()-t.size(); i++){
        if(s.substr(i,t.size())==t){
            s.erase(i,t.size());
            if(sub.size() && s.size()) s.insert(i, sub);
            else if(s.size()==0 && sub.size()) s=sub;
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    while(cin>>n && n){
        cin.ignore();
        string rule[20], sub[20];
        for(int i=0; i<n; i++){
            getline(cin, rule[i]);
            getline(cin, sub[i]);
        }
        string s;
        getline(cin, s);
        for(int i=0; i<n; i++){
            while(s.size()>=rule[i].size()&&findstr(s, rule[i], sub[i]));
        }
        cout<<s<<endl;
    }
    
}