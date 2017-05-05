/*
    Author: Nada Alaa  
    Idea:
        - Find the lengths of substrings of X's in all knots that 
            lie between index i and i + length-of-maximum-digit
        - These intersections represents a digit in the current knot
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

using namespace std;


class QuipuReader {
public:
    vector <int> readKnots(vector <string> knots) {
        vector<int> ans(knots.size(),0);
        int i=0;
        while(i<knots[0].size()){
            int maxlen=0;
            for(int j=0; j<knots.size(); j++){
                int len=0;
                while(knots[j][i+len]=='X'){
                    len++;
                }
                maxlen=max(maxlen, len);
            }
            int digit[20]={0};
            for(int k=0; k<knots.size(); k++){
                for(int j=i; j<i+maxlen; j++){
                    digit[k]+=knots[k][j]=='X';
                }
                if(maxlen) ans[k]=ans[k]*10+digit[k];
            }
            i+=max(maxlen, 1);
        }
        return ans;
    }
};