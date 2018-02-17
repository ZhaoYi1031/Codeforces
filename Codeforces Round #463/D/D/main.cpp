/*模板*/
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)

using namespace std;
const int N = 10010;
ll ans, n , m, a[N], b[N], f[N], g[N], zy[110][110];
ll vis[N];
ll fac(ll n){
    return 0;
}
ll C(ll n, ll m){
    return f[n]/f[m]/f[n-m];
}
int main() {
    cout << __gcd(4,8) << endl;
    f[0] = 1;
    f[1] = 1;
    rep (i,2,20){
        f[i] = f[i-1]*i;
    }
    
//    cin >> n >> m;
    ll last;
    rep (n,1,10){
        last = 0;
        rep (k,1,6){
            g[1] = 1;
            rep (i,2,n){
                g[i] = 1;
                rep (j,1,k){
                    g[i] *= i;
                }
            }
            ans = 0;
            rep (i,1,n){
                ans = ans + C(n, i)*g[i];
            }
//            cout << n << " " << k << " : " << ans << endl;
            if (k!=1){
                cout << ans-last << " ";
                zy[n][k-1] = ans-last;
            }
            last = ans;
            
        }
        cout << endl;
    }
    cout << endl << endl;
    rep (n,1,10){
        rep (k,2,6){
            cout << zy[n][k]-zy[n][k-1] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    rep (n,1,10){
        rep (k,2,6){
            cout << zy[n][k]-zy[n][k-1]*n << " ";
        }
        cout << endl;
    }
//    cout << ans << endl;
    return 0;
}
