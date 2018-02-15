//
//  main.cpp
//  A
//
//  Created by ohazyi on 2017/10/15.
//  Copyright © 2017年 ohazyi. All rights reserved.
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
ll ans, n , m, x, a[N], b[N];
ll vis[N];

int main() {
    
    cin >> n >> m;
    
    rep (i,1,n){
        cin >> a[i];
    }
    rep (i,1,m){
        cin >> b[i];
    }
    
    ll res = 1e18;
    res += 10;
    rep (k,1,n){
        ans = -1e18;
        ans -= 10;
        rep (i,1,n)
        rep (j,1,m){
            if (i == k)
                continue;
            if (a[i] * b[j] >= ans){
                ans = a[i]*b[j];
            }
        }
        if (ans < res){
            res = ans;
        }
    }
    cout << res << endl;
    return 0;
}
