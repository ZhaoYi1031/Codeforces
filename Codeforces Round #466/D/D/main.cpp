//
//  main.cpp
//  Poj 3255 SPFA
//
//  Created by 赵奕 on 16/3/15.
//  Copyright © 2016年 赵奕. All rights reserved.
//

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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
using namespace std;
//typedef long long ll;
const int N = 200010;
int n,a[N],ans,l,r;
char s[N];
int mymax(int k){
    int res = a[k];
    rep (i,1,4){
        res = max(res, a[k-i]);
    }
    return res;
}
int mymin(int k){
    int res = a[k];
    rep (i,1,4){
        res = min(res, a[k-i]);
    }
    return res;
}
int main() {
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
    }
    scanf("%s", s+1);
//    s[0]='!';
//    printf("!!%s\n", s);
    l = -1e9;
    r = 1e9;
    rep (i,5,n){
        if (s[i] == '1'){
            if (s[i-1] == '0' && s[i-2] == '0' && s[i-3] == '0' && s[i-4] == '0'){
                l = max(l, mymax(i)+1);
            }
            continue;
        }
        if (s[i-1] == '1' && s[i-2] == '1' && s[i-3] == '1' && s[i-4] == '1'){
            r = min(r, mymin(i)-1);
        }
    }
    cout << l << " " << r << endl;
    return 0;
}
