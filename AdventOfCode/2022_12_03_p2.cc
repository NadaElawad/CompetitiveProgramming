#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

void IncrementArray(int arr[], string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            arr[s[i]-'a']++;
        } else {
            arr[s[i]-'A'+26]++;
        }
    }
}

int main()
{
    string s;
    int ans = 0, t = 0;
    int arr1[90] = {0}, arr2[90] = {0}, arr3[90] = {0};
    while (cin >> s) {
        t++;
        if (t == 1) {
            IncrementArray(arr1, s);
        }
        if (t == 2) {
            IncrementArray(arr2, s);
        }
        if (t == 3) {
            IncrementArray(arr3, s);
            for (int i = 0; i < 26*2; ++i) {
                if (arr1[i] && arr2[i] && arr3[i]) {
                    ans+=i+1;
                    break;
                }
            }
            t = 0;
            memset(arr1, 0, sizeof(arr1));
            memset(arr2, 0, sizeof(arr2));
            memset(arr3, 0, sizeof(arr3));
        }
    }
    cout << ans << endl;
    return 0;
}
