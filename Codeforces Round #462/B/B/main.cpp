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
int ans, n , m, x, a[N], b[N];
int vis[N];

int main() {
    cin >> n;
    if (n > 36){
        cout << -1 << endl;
        return 0;
    }
    if (n % 2){
        m = n / 2;
        rep (i,1,m){
            cout << 8;
        }
        cout << 6 << endl;
        return 0;
    }
    m = n / 2;
    rep (i,1,m){
        cout << 8;
    }
    cout << endl;
    
    return 0;
}
