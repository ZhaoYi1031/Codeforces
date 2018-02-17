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

const int N = 1000010;
int ans, k, n , m, x, y, a[N], p, q;
int main() {
    cin >> n >> x >> y;
    int h;
    rep (i,0,n/x){
        h = n-i*x;
        if ((h % y)==0){
            p = i;
            q = h / y;
            break;
        }
    }
    if (p==0&&q==0){
        cout << -1 << endl;
        return 0;
    }
    rep (i,1,p){ // [ (i-1)*p+1, i*p]]
        rep (j,(i-1)*x+1,i*x-1){
            a[j] = j+1;
        }
        a[i*x] = (i-1)*x+1;
    }
    h = p*x;
    rep (i,1,q){
        rep (j,h+(i-1)*y+1,h+i*y-1){
            a[j] = j+1;
        }
        a[h+i*y] = h+(i-1)*y+1;
    }
    rep (i,1,n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
