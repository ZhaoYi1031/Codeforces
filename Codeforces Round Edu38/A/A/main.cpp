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
bool isV(char c){
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c=='y');
}
int main() {
    cin >> n;
    cin >> s;
    while (true){
        bool zy = true;
        rep (i,1,(int)s.size()-1){
            if (isV(s[i-1]) && isV(s[i])){
                s.erase(s.begin()+i);
//                cout << s << endl;
                zy = false;
                break;
            }
        }
        if (zy)
            break;
    }
    cout << s << endl;
    return 0;
}
