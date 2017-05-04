/*
    Author: Nada Alaa
    
    Idea:
    - Concatenating all strings in one string and rotating it to have all blocks on one side (to make it easy when calculating the dots at idx=0 & idx=N-1)
    - Saving the size and index of each block helps me calculate the resulting dot blocks when I remove X block.
    - Saving the maximum(lexigraphical) vector and compare it each time
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


class LargestGap {
public:
    bool check(vector<int> &order, vector<int> &maxorder, int shift, int diff, char c){
        if(maxorder.size()==0) return true;
        for(int i=0; i<order.size(); i++) {
            if(!(maxorder[i]==order[i])) return order[i]>maxorder[i];
        }
        return c=='.'&&shift&&!diff;
    }
    int getLargest(vector <string> board) {
        vector<pair<int,int> > dots, cross;
        string all;
        
        for(int i=0; i<board.size(); i++) all+=board[i];
        
        int i=0, shift=0;
        
        //Rotating the string to have all blocks on one side (to make it easy when calculating the dots at idx=0 & idx=N-1)
        while(shift<all.size() && all[shift]==all[all.size()-1]) shift++;
        all = all.substr(shift, all.size()-shift)+all.substr(0, shift);
        
        while(i<all.size()){
            int j=i;
            while(j<all.size() && all[j]=='.') j++;
            if(j!=i){
                dots.push_back({j-i, i});
            }
            i=j;
            while(j<all.size() && all[j]=='X') j++;
            if(j!=i){
                cross.push_back({j-i, i});
            }
            i=j;
        }
        i=0;
        vector<int> maxorder;
        int ans=1e5, sz=(int)dots.size(), mod=(int)all.size();
        for(int j=0; j<cross.size(); j++){
            vector<int> order;
            int maxi=0;
            while(i<dots.size() && dots[i].second<cross[j].second){
                i++;
            }
            if((dots.size() && dots[i%sz].second>cross[j].second) || i==sz) maxi+=dots[i%sz].first;
            if((dots.size() && dots[(i-1+sz)%sz].second<cross[j].second) || i==0) maxi+=dots[(i-1+sz)%sz].first;
            for(int k=0; k<dots.size(); k++){
                if(k==i%sz||k==(i-1+sz)%sz) continue;
                order.push_back(dots[k].first);
            }
            order.push_back(maxi);
            sort(order.rbegin(), order.rend());
            if(check(order, maxorder, shift, mod-cross[j].second-cross[j].first, all[0])){
                maxorder=order;
                if(all[0]=='.'&&shift&&cross[j].second+cross[j].first>=mod) ans=0;
                else ans=(cross[j].second+shift)%mod;
            }
        }
        return ans;
    }
};