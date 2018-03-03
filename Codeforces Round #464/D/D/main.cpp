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
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;
const int N = 1010;
int ans, n , m, a[N], b[N], f[N];
vector<int> v[N];
int vis[N];
string s, t;
int find(int x)
{
    if (f[x]==x)
        return x;
    return (f[x] = find(f[x]));
}
void unite(int x,int y)
{
    int fx,fy;
    fx = find(x);
    fy = find(y);
    if (fx<fy){
        f[fy] = fx;
    }
    else{
        f[fx] = fy;
    }
}
int main() {
    cin >> n;
    cin >> s >> t;
    rep (i,0,25){
        f[i] = i;
    }
    memset(vis,0,sizeof(vis));
    memset(b,0,sizeof(b));
    rep (i,0,n-1){
        vis[s[i]-'a'] = 1;
        vis[t[i]-'a'] = 1;
        unite(s[i]-'a', t[i]-'a');
    }
    int h;
    rep (i,0,25){
        if (vis[i]){
            h = find(i);
            b[h] = 1;
            if (h != i)
                v[h].push_back(i);
        }
    }
    ans = 0;
    rep (i,0,25){
        if (b[i] == 1){
            ans+=v[i].size();
        }
    }
    cout << ans << endl;
    rep (i,0,25){
        if (b[i] == 1){
            rep (j,0,(int)v[i].size() - 2){
                printf("%c %c\n", 'a'+v[i][j], 'a'+v[i][j+1]);
            }
            if (v[i].size() > 0)
                printf("%c %c\n", 'a'+v[i][v[i].size()-1], 'a'+i);
        }
    }
    return 0;
}
