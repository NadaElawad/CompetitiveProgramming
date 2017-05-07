/*
    Author: Nada Alaa   
    Idea:
        - Going over all words in the dictionary and trying to reach every word from the current input word by calculating the difference in the number of correct characters
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
    cin>>n;
    cin.ignore();
    cin.ignore();
    while(n--){
        string word;
        vector<string> dic;
        while(getline(cin, word) && word!="#"){
            dic.push_back(word);
        }
        while(getline(cin, word) && word!="#"){
            vector<int> ans;
            bool flag = 0;
            for(int i=0; i<dic.size(); i++){
                if(word==dic[i]) {
                    flag=1; break;
                }
                int k=0;
                if(dic[i].size()==word.size()+1 && word.size()){
                    k=0;
                    for(int j=0; j<dic[i].size(); j++){
                        if(dic[i][j]==word[k]) k++;
                    }
                    if(k==word.size()) {ans.push_back(i); continue;}
                }
                else if(dic[i].size()==word.size()-1 && dic[i].size()){
                    k=0;
                    for(int j=0; j<word.size(); j++){
                        if(dic[i][k]==word[j]) k++;
                    }
                    if(k==dic[i].size()) {ans.push_back(i); continue;}
                }
                else if(dic[i].size()==word.size() && word.size()){
                    k=0;
                    for(int j=0; j<dic[i].size(); j++){
                        if(dic[i][j]==word[j]) k++;
                    }
                    if(k==word.size()-1) ans.push_back(i);
                }
            }
            if(flag) cout<<" is correct\n";
            else if(!ans.size()) cout<<word<<":\n";
            else {
                cout<<word<<":";
                for(int i=0; i<ans.size(); i++) cout<<" "<<dic[ans[i]];
                cout<<'\n';
            }
        }
        if(n) cout<<'\n';
    }
}