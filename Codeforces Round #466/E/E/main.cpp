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
ll Lowbit(ll x)
{
    return x&(-x);
}
void Init(ll n){
    for(ll i=1;i<=n;i++){
        idx[i]=a[i];
        for(ll j=1;j<Lowbit(i);j<<=1){
            idx[i]=min(idx[i],idx[i-j]);
        }
    }
}
ll Query(ll l,ll r){
    ll ans=a[r];
    while(true){
        ans=min(ans,a[r]);
        if(r==l) break;
        for(r-=1;r-l>=Lowbit(r);r-=Lowbit(r)){
            ans=min(ans,idx[r]);
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    ll sum = 0;
    rep (i, 1, n){
        cin >> a[i];
        sum += a[i];
    }
    Init(n);
    ans = 0;
    rep (i,1,n){
        if (i < m){
            continue;
        }
        f[i] = f[i-m] + Query(i-m+1, i);
        f[i] = max(f[i-1], f[i]);
        ans = max(ans, f[i]);
    }
    cout << sum-ans << endl;
    return 0;
}
