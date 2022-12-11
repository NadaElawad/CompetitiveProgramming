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
    int ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            bool exposed = true;
            // horizontal check left.
            for (int k = 0; k < j; ++k) {
                if (vec[i][k] >= vec[i][j]) { exposed = false; break; }
            }
            if (exposed) { ans++; continue; }
            exposed = true;
            // horizontal check right.
            for (int k = j+1; k < vec[i].size(); ++k) {
                if (vec[i][k] >= vec[i][j]) { exposed = false; break; }
            }
            if (exposed) { ans++; continue; }
            exposed = true;
            // vertical check up.
            for (int k = 0; k < i; ++k) {
                if (vec[k][j] >= vec[i][j]) { exposed = false; break; }
            }
            if (exposed) { ans++; continue; }
            exposed = true;
            // vertical check down.
            for (int k = i+1; k < vec.size(); ++k) {
                if (vec[k][j] >= vec[i][j]) { exposed = false; break; }
            }
            if (exposed) { ans++; continue; }
        }
    }
    cout << ans << endl;
    return 0;
}
