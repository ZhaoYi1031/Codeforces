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

#define rep(i,a,b) for (ll i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (ll i = (a); i >= (b); --i)

using namespace std;
const ll N = 1000010;
ll ans, ansi, n , m, s, f, a[N], b[N];
int main() {
    cin >> n;
    b[0] = 0;
    rep (i,1,n){
        cin >> a[i];
        b[i] = b[i-1]+a[i];
    }
    cin >> s >> f;
    f--;
    m = f-s;
    ans = -1;
    ll tot;
    ll k;
    rep (i,1,n){
        if (s >= i){
            tot = b[1+f-i] - b[1+s-i-1];
        }else if (f <= i-1){
            k = n-i+2;
            tot = b[f+k-1] -  b[s-1+k-1];
        }else{
            k = n-i+2;
            tot = b[1+f-i] + b[n]-b[s-1+k-1];
//            cout << "!!!";
        }
        if (tot > ans){
            ansi = i;
            ans = tot;
        }
//        cout << i  << " " << tot << endl;
    }
    cout << ansi << endl;
    return 0;
}
