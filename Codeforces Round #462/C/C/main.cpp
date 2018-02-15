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

const int N = 20010;
int ans, k, n , m, x, a[N], f[N][3], g[N][3], stack[N], lis[N];
int vis[N];
int main() {
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
    }
    int cnt = 0;
    rep (i,1,n){
        if (a[i] == 1){
            cnt++;
        }
        f[i][1] = 1;
    }
    rep (i,1,n){
        rep (j,i+1,n){
            if (a[j] >= a[i]){
                lis[j] = max(lis[j], lis[i]+1);
            }
        }
    }
    
    rep(i,1,n){
        f[i][2] = lis[i]+1;
    }
    
    
    memset(lis, 0, sizeof(lis));
    cnt = 0;
    rep2 (i,n,1){
        if (a[i] == 1){
            cnt++;
        }
        g[i][1] = cnt;
    }
    rep2 (i,n,1){
        rep2 (j,i-1,1){
            if (a[j] <= a[i]){
                lis[j] = max(lis[j], lis[i]+1);
            }
        }
    }
    rep(i,1,n){
        g[i][2] = lis[i]+1;
    }
    
    ans = 0;
    int top;
    rep (i,1,n){
        top = 0;
        stack[top] = 1e9;
        rep (j,i,n){
            if(a[j]<=stack[top]){stack[++top]=x;}
            else
            {
                int low=0,high=top,mid;
                while(low<high){
                    mid=(low+high)>>1;
                    if(a[j]<=stack[mid])
                        low=mid+1;
                    else
                        high=mid-1;
                }
                stack[low]=a[j];
            }
            if (top + f[i-1][a[j]] + g[j+1][a[i]] > ans)
                ans = top + f[i-1][a[j]] + g[j+1][a[i]];
        }
    }
    
    cout << ans << endl;
    return 0;
}
