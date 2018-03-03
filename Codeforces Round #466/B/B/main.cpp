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
const int N = 2010;
ll ans, n , k, m, A, B, cost;

int main() {
    cin >> n >> k >> A >> B;
    if (k == 1){
        ans = (n-1)*A;
        cout << ans << endl;
        return 0;
    }
    ans = 0;
    while (n != 1){
        if ((n % k) == 0){
            cost = A*(n - n/k);
            if (cost < B){
                ans += cost;
            }else{
                ans += B;
            }
            n /= k;
            continue;
        }
        m = n / k;
        m *= k;
        if (m  == 0){
            m = 1;
        }
        ans += A*(n - m);
        n = m;
    }
    cout << ans << endl;
    return 0;
}
