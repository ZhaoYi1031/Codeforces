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
const int N = 1000100;
int ans, n , m, x, y, z, zy[N][11], g[N];
int vis[N];
int fff(int k){
    int res = 1;
    while (k != 0){
        if (k % 10)
            res *= (k % 10);
        k /= 10;
    }
    return res;
}
int calc(int k){
    if (g[k] != 0)
        return g[k];
    if (k < 10)
        return k;
    g[k] = calc(fff(k));
    return g[k];
}
int main() {
    int h;
    rep (i,1,1e6){
        rep (j,1,9){
            zy[i][j] = zy[i-1][j];
        }
        h = calc(i);
        zy[i][h]++;
    }
    cin >> n;
    rep (i, 1, n){
        cin >> x >> y >> z;//;a[i] >>b[i] >> c[i];
        cout << zy[y][z]-zy[x-1][z] << endl;
    }
    return 0;
}
