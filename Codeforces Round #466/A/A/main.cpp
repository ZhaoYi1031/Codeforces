#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
typedef long long ll;

#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;
const int N = 1010;
int ans, n , m, a[N], b[N], c[N];
string s;

int main() {
    cin >> n >> m;
    rep (i,1,n){
        cin >> a[i];
        b[a[i]]++;
    }
    c[0] = b[0];
    rep (i,1,100){
        c[i] = c[i-1]+b[i];
    }
    
    ans = 0;
    rep (i,0,100){
        ans = max(c[i+m]-c[i-1], ans);
    }
    cout << n-ans << endl;
    return 0;
}
