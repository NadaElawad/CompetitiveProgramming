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
#include <complex>
#define ll long long
using namespace std;
int main(){
    string s;
    while(getline(cin,s) && s!="()"){
        int flag = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') flag++;
        }
        stringstream ss; ss << s;
        stack<double> st;
        double v;
        do{
            while(ss.peek()=='(' || ss.peek()==' ') ss.get();
            if(ss.peek()!=')'){
                ss>>v;
                st.push(v);
            }else {
                flag--;
                ss.get();
                double p, e1, e2;
                e2=st.top(); st.pop();
                e1=st.top(); st.pop();
                p=st.top(); st.pop();
                st.push(p * (e1 + e2) + (1 - p) * (e1 - e2));
            }
        }while(flag);
        cout<<fixed<<setprecision(2)<<st.top()<<endl;
    }
}
