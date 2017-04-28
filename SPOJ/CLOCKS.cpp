/*
	Author: Nada Alaa
	
	Idea:
    - Thinking in a brute force manner, since the order of applying masks is irrelevant to the final answer, I can try applying each mask a maximum of 3 times (since applying it more than 3 times would give a same old result)
    - Base case is to check if my concatenated cells are all equal to zero, then I save the minimum of steps, which is part of my function call
    - A separate move function that can apply a certain move a certain number of times and return the updated string (matrix representation)
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
using namespace std;
string Move(string s, int i, int times){
    while (times--) {
        if(i==1){
            s[0]=((s[0]+1-'0')%4+'0');
            s[1]=((s[1]+1-'0')%4+'0');
            s[3]=((s[3]+1-'0')%4+'0');
            s[4]=((s[4]+1-'0')%4+'0');
        }
        else if(i==2){
            s[0]=((s[0]+1-'0')%4+'0');
            s[1]=((s[1]+1-'0')%4+'0');
            s[2]=((s[2]+1-'0')%4+'0');
        }
        else if(i==3){
            s[1]=((s[1]+1-'0')%4+'0');
            s[2]=((s[2]+1-'0')%4+'0');
            s[4]=((s[4]+1-'0')%4+'0');
            s[5]=((s[5]+1-'0')%4+'0');
        }
        else if(i==4){
            s[0]=((s[0]+1-'0')%4+'0');
            s[3]=((s[3]+1-'0')%4+'0');
            s[6]=((s[6]+1-'0')%4+'0');
        }
        else if(i==5){
            s[1]=((s[1]+1-'0')%4+'0');
            s[3]=((s[3]+1-'0')%4+'0');
            s[4]=((s[4]+1-'0')%4+'0');
            s[5]=((s[5]+1-'0')%4+'0');
            s[7]=((s[7]+1-'0')%4+'0');
        }
        else if(i==6){
            s[2]=((s[2]+1-'0')%4+'0');
            s[5]=((s[5]+1-'0')%4+'0');
            s[8]=((s[8]+1-'0')%4+'0');
        }
        else if(i==7){
            s[3]=((s[3]+1-'0')%4+'0');
            s[4]=((s[4]+1-'0')%4+'0');
            s[6]=((s[6]+1-'0')%4+'0');
            s[7]=((s[7]+1-'0')%4+'0');
        }
        else if(i==8){
            s[6]=((s[6]+1-'0')%4+'0');
            s[7]=((s[7]+1-'0')%4+'0');
            s[8]=((s[8]+1-'0')%4+'0');
        }
        else if(i==9){
            s[4]=((s[4]+1-'0')%4+'0');
            s[5]=((s[5]+1-'0')%4+'0');
            s[7]=((s[7]+1-'0')%4+'0');
            s[8]=((s[8]+1-'0')%4+'0');
        }
    }
    return s;
}
int minLen;
string minMoves;
void f(int move, string s, string totalmoves){
    if(s=="000000000"){
        if(totalmoves.size()<minLen || (totalmoves.size()==minLen && totalmoves<minMoves)){
            minMoves=totalmoves;
            minLen=(int)totalmoves.size();
        }
        return;
    }
    if(move>9) return;
    f(move+1, s, totalmoves);
    f(move+1, Move(s,move,1), totalmoves+char(move+'0'));
    f(move+1, Move(s,move,2), totalmoves+char(move+'0')+char(move+'0'));
    f(move+1, Move(s,move,3), totalmoves+char(move+'0')+char(move+'0')+char(move+'0'));
}
int main(){
    string s;
    minLen = 1e5;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int tmp; scanf("%d",&tmp);
            s+=tmp+'0';
        }
    }
    f(1, s, "");
    for(int i=0; i<minMoves.size(); i++) printf("%d ", minMoves[i]-'0');
    printf("\n");
}
