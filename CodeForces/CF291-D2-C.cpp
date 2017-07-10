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
struct TrieNode{
    TrieNode *children[3];
    bool isLeaf;
};
void InsertWord(string &word, TrieNode *root){
    if(root == NULL){
        root = new TrieNode();
    }
    
    TrieNode *traverse = root;
    for(int i = 0; i < word.size(); i++){
        if(traverse->children[word[i]-'a'] == NULL){
            traverse->children[word[i]-'a'] = new TrieNode();
        }
        traverse = traverse->children[word[i]-'a'];
    }
    traverse->isLeaf = true;
}
bool SearchWord(string &word, TrieNode *root, bool flag, int idx){
    if(idx == word.size()){
        return root->isLeaf && flag;
    }
    bool ans = false;
    for(int i = 0; i < 3; i++){
        if(root->children[i] == NULL) continue;
        if(i == word[idx]-'a') ans |= SearchWord(word, root->children[i], flag, idx+1);
        else if(!flag) ans |= SearchWord(word, root->children[i], true, idx+1);
    }
    return ans;
}
int main(){
    int n, m;
    while(cin>>n>>m){
        TrieNode *root = new TrieNode();
        while(n--){
            string s; cin>>s;
            InsertWord(s, root);
        }
        while(m--){
            string s; cin>>s;
            bool ans = SearchWord(s, root, false, 0);
            if(ans) cout<<"YES\n";
            else cout<<"NO\n";
        }
        delete root;
    }
}
