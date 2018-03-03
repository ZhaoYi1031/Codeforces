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
int ans, n , m, a[N], b[N];
int vis[N];
string s;
int main() {
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
    }
    int x,y,z;
    rep (i,1,n){
        x = i;
        y = a[x];
        z = a[y];
        if (x != y && y != z && x != z){
            if (a[z] == x){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
