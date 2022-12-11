/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string x;
    int current_sum = 0;
    std::vector<int> vec;
    while(getline(cin, x)) {
        if (x == "") {
            vec.push_back(current_sum);
            current_sum = 0;
        } else {
            current_sum += stoi(x);
        }
    }
    vec.push_back(current_sum);
    sort(vec.begin(), vec.end());
    cout << vec[vec.size()-1]+vec[vec.size()-2]+vec[vec.size()-3] << endl;
}
