#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

bool IsUniqueCharacters(const string& s, int start, int end) {
    int arr[26] = {0};
    for (int i=start; i<end; ++i) {
        arr[s[i]-'a']++;
        if (arr[s[i]-'a'] > 1) return false;
    }
    return true;
}

int main()
{
    string s;
    int ans = 0, step = 4;
    cin >> s;
    for (int i = 0; i + step <= s.size(); ++i) {
        if (IsUniqueCharacters(s, i, i+step)) {
            ans = i+step;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
