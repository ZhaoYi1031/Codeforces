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
const int N = 2000010;
int ans, n , m, a[N];

int main() {
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
    }
    
    ans = 0;
    rep (i,1,n){
        ans = max(ans, min(a[i]-1, 1000000-a[i]));
    }
    cout << ans << endl;
    return 0;
}
