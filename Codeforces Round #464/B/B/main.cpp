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
const ll N = 200010;
ll rest, resn, ans, n , m, x, a[N];
int main() {
    cin >> n >> m;
    
    rep (i,1,m){
        cin >> a[i];
    }
    if (n == 0){
        cout << 1 << " " << 0 << endl;
        return 0;
    }
    
    ans = 1e18;
    resn = 1;
    rest = 0;
    rep (i,1,m){
        x = n / a[i];
//        if (x * a[i] > ans)
        if ((n%a[i]) <ans)
        {
            ans = n%a[i];//x*a[i];
            rest = i;
            resn = x;
        }
    }
    cout << rest << " " << resn << endl;
    return 0;
}
