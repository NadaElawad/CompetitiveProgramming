/*
    Author: Nada Alaa
    Idea: 
        - With the help of bit manipulations, I mask all possible combinations for guitars (2^10) and keep the maximum number of songs as I go.
        - In tie, I compare different combinations using string comparison and keep the minimum.
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


class GuitarConcert {
public:
    bool comp(vector<string> a, vector<string> b){
        if(a.size()==0) return true;
        for(int i=0; i<a.size(); i++){
            if(a[i]<b[i]) return false;
            else if(a[i]>b[i]) return true;
        }
        return false;
    }
    vector <string> buyGuitars(vector <string> guitarNames, vector <string> guitarSongs) {
        int sz = (1<<guitarNames.size());
        bool canBePlayed[52][52]={false};
        for(int i=0; i<guitarSongs.size(); i++){
            for(int j=0; j<guitarSongs[i].size(); j++){
                canBePlayed[i][j]=guitarSongs[i][j]=='Y';
            }
        }
        vector<int> allpossible;
        int minCost = 1e9, maxSize = 0;
        for(int i=1; i<sz; i++){
            int currCost=0;
            set<int> songs;
            for(int j=0; j<guitarNames.size(); j++){
                if(i&(1<<j)){
                    for(int k=0; k<guitarSongs[j].size(); k++){
                        if(canBePlayed[j][k]) songs.insert(k);
                    }
                    currCost++;
                }
            }
            if(songs.size()>maxSize || (currCost < minCost && songs.size() == maxSize)){
                minCost = currCost;
                maxSize = (int)songs.size();
                allpossible.clear();
                allpossible.push_back(i);
            }else if(songs.size() && currCost == minCost && songs.size() == maxSize){
                allpossible.push_back(i);
                minCost = currCost;
            }
        }
        vector<string> ans;
        for(int i=0; i<allpossible.size(); i++){
            vector<string> vec;
            for(int j=0; j<guitarNames.size(); j++){
                if(allpossible[i]&(1<<j)){
                    vec.push_back(guitarNames[j]);
                }
            }
            sort(vec.begin(), vec.end());
            if(comp(ans,vec)) ans=vec;
        }
        return ans;
    }
};