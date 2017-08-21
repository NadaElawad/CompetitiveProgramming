#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;
int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while (a < c) {
        a = min(a + b, c);
        c = max(c - d, a);
    }
    printf("%d\n", a);
}
