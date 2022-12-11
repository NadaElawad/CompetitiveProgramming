/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    int ans = 0;
    while (cin >> s) {
        int size = s.size()/2;
        int arr1[90] = {0}, arr2[90] = {0};
        for (int i = 0; i < size; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                arr1[s[i]-'a']++;
            } else {
                arr1[s[i]-'A'+26]++;
            }
            if (s[i+size] >= 'a' && s[i+size] <= 'z') {
                arr2[s[i+size]-'a']++;
            } else {
                arr2[s[i+size]-'A'+26]++;
            }
        }
        for (int i = 0; i < 26*2; ++i) {
            if (arr1[i] && arr2[i]) {
                ans+=i+1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
