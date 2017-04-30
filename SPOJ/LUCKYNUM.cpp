/*
	Author: Nada Alaa
	
	Idea:
    - Recusively trying sequences of different lengths and only keeping track of the number of eights in the sequence
    - Base case is reaching a sequence that its modulus with respect to X is zero, since we only need current modulus and not the original sequence, I take the modulus on the go
    - Added a flag parameter in the state definition since the sequence can't have 6's followed by 8's
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
int x, len, e;
void f(int i, int eights, bool flag, int mod){
    if(!mod && i){
        if(len>i || (len==i && eights<e) || !len){
            len=i;
            e=eights;
        }
        return;
    }
    if(i>=200) return;
    if(flag) f(i+1,eights,true,(mod*10+6)%x);
    else {
        f(i+1,eights+1,false,(mod*10+8)%x);
        f(i+1,eights,true,(mod*10+6)%x);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        len=0; e=0;
        scanf("%d",&x);
        f(0,0,0,0);
        string s;
        for(int i=0; i<e; i++) s+='8';
        while(s.size()<len) s+='6';
        if(s.size()) cout<<s<<endl;
        else cout<<-1<<endl;
    }
}