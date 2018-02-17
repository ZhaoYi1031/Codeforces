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
string s,t;
int main() {
    cin >> s;
    cout << s;
    rep2 (i,s.size()-1,0){
        cout << s[i];
    }
    cout << endl;
    return 0;
}
