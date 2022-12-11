#include <iostream>
#include <unordered_map>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;
    string s;
    while(cin>>s) {
        vec.push_back(s);
    }
    int ans = 0, max_ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            int ans = 0, incremental = 0;
            // horizontal check left.
            for (int k = j-1; k >= 0; --k) {
                if (vec[i][k] >= vec[i][j]) { incremental++; break; }
                incremental++;
            }
            ans = incremental;
            incremental = 0;
            
            // horizontal check right.
            for (int k = j+1; k < vec[i].size(); ++k) {
                if (vec[i][k] >= vec[i][j]) { incremental++; break; }
                incremental++;
            }
            ans *= incremental;
            incremental = 0;
            
            // vertical check up.
            for (int k = i-1; k >= 0; --k) {
                if (vec[k][j] >= vec[i][j]) { incremental++; break; }
                incremental++;
            }
            ans *= incremental;
            incremental = 0;
            
            // vertical check down.
            for (int k = i+1; k < vec.size(); ++k) {
                if (vec[k][j] >= vec[i][j]) { incremental++; break; }
                incremental++;
            }
            ans *= incremental;
            max_ans = max(max_ans, ans);
        }
    }
    cout << max_ans << endl;
    return 0;
}
