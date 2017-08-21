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

using namespace std;


class PalindromizationDiv1 {
public:
    int n;
    int repcost[27][27], dp[51][51], conv[27][27];
    string wrd;
    int count(int i, int j){
        if(j<=i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        ans = min(ans, count(i, j-1)+conv[26][wrd[j]-'a']);
        ans = min(ans, count(i+1, j-1)+conv[wrd[i]-'a'][wrd[j]-'a']);
        ans = min(ans, count(i+1, j)+conv[wrd[i]-'a'][26]);
        return dp[i][j] = ans;
    }
    int getMinimumCost(string word, vector <string> operations) {
        n = (int)word.size();
        wrd = word;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=26; i++){
            for(int j=0; j<=26; j++){
                repcost[i][j]=conv[i][j]=1e9;
            }
            repcost[i][i]=conv[i][i]=0;
        }
        for(int i=0; i<operations.size(); i++){
            stringstream ss;
            ss << operations[i];
            string op;
            ss >> op;
            if(op == "add"){
                string c; int cost;
                ss >> c;
                ss >> cost;
                repcost[26][c[0]-'a'] = cost;
            }else if(op == "erase"){
                string c; int cost;
                ss >> c;
                ss >> cost;
                repcost[c[0]-'a'][26] = cost;
            }else{
                string c1, c2; int cost;
                ss >> c1;
                ss >> c2;
                ss >> cost;
                repcost[c1[0]-'a'][c2[0]-'a'] = cost;
            }
        }
        for(int k=0; k<=26; k++){
            for(int i=0; i<=26; i++){
                for(int j=0; j<=26; j++){
                    repcost[i][j]=min(repcost[i][k]+repcost[k][j], repcost[i][j]);
                }
            }
        }
        for(int k=0; k<=26; k++){
            for(int i=0; i<=26; i++){
                for(int j=0; j<=26; j++){
                    conv[k][i]=min(repcost[k][j]+repcost[i][j], conv[k][i]);
                }
            }
        }
        return count(0, n-1)>=1e9? -1: count(0, n-1);
    }
};