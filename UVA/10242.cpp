/*
    Author: Nada Alaa
    Idea: 
        - Convert input to integers first to be able to test equality easily (I choose 10^4 instead of 10^3 because apparently it caused a precision error)
        - Find the two similar points and compute the fourth by adding the remaining points and subtracting the common point
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
int main(){
    int arr[4][2];
    double x1, y1;
    while(cin>>x1>>y1){
        arr[0][0] = x1*10000.0;
        arr[0][1] = y1*10000.0;
        for(int i=1; i<4; i++){
            cin>>x1>>y1;
            arr[i][0] = x1*10000.0; arr[i][1] = y1*10000.0;
        }
        int x = arr[0][0]+arr[1][0]+arr[2][0]+arr[3][0];
        int y = arr[0][1]+arr[1][1]+arr[2][1]+arr[3][1];
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                if(arr[i][0]==arr[j][0]&&arr[i][1]==arr[j][1]){
                    cout<<fixed<<setprecision(3)<<(x-3*arr[i][0])/10000.0<<" "<<(y-3*arr[i][1])/10000.0<<endl;
                    i=j=100;
                }
            }
        }
    }
}