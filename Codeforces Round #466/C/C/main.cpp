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
const int N = 40010;
int n,m,a[N],l;
string s;
bool b[110];
int main() {
    cin >> n >> m;
    cin >> s;
    memset(b,false,sizeof(b));
    int mi = 1e9;
    for (auto i: s){
        b[i-'a'] = true;
        mi = min(mi, i-'a');
    }
    char ch;
    if (n < m){
        cout << s;
        ch = mi+'a';
        rep (i,1,m-n){
            cout << ch;
        }
        cout << endl;
        return 0;
    }
    int h, pos;
    rep2 (i,m-1,0){
        h = s[i] - 'a';
        pos = -1;
        rep (j,h+1,25){
            if (b[j]){
                pos = j;
                break;
            }
        }
        if (pos != -1){
            rep (j, 0, i-1){
                cout << s[j];
            }
            ch = pos+'a';
            cout << ch;
            ch = mi+'a';;
            rep (j,1,m-i-1){
                cout << ch;
            }
            cout << endl;
            return 0;
        }
    }
    
    return 0;
}
