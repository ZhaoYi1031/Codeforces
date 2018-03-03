//
//  main.cpp
//  E
//
//  Created by ohazyi on 2018/2/24.
//  Copyright © 2018年 ohazyi. All rights reserved.
//

#include <iostream>
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
ll ans, n , m, a[N], idx[N], f[N];

int main() {
    cin >> n >> m;
    ll sum = 0;
    multiset<ll> v;
    rep (i, 1, n){
        cin >> a[i];
        sum+=a[i];
        if (i > m){
            sum-=a[i-m];
            v.erase(v.find(a[i-m]));
        }
        v.insert(a[i]);
        f[i] = f[i-1]+a[i];
        if (i >= m)
            f[i] = min(f[i], f[i-m]+sum - *v.begin());
    }
    
    cout << f[n] << endl;
    return 0;
}
