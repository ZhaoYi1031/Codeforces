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
const ll N = 40010;
ll ans, n , m, x, a[N];
ll isSquare(ll k){
    ll res = sqrt(k);
    if (k == res*res){
        return res;
    }
    return 0;
}
int main() {
    ll t, h;
    cin >> t;
    rep (_,1,t){
        cin >> x;
        bool zy = false;
        rep (i,1,40000){
        
            h = isSquare(x+ll(i)*ll(i));
            m = h/i;
            if (m == 0)
                continue;
            int q = h/m;
            if (h>0 && q == i){
                cout << h << " " << m << endl;
                zy = true;
                break;
            }
        }
        if (!zy)
            cout << -1 << endl;
    }
    return 0;
}
