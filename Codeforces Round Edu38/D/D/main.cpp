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
#define rep(i,a,b) for (ll i = (a); i <= (b); ++i)
#define rep(i,a,b) for (ll i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
const ll N = 200010;
const ll M = 800010;
//vector<ll> v[N];
ll c[N], a[N];
ll dis[N];
struct Edge{
    ll to,cost,next;
};
Edge e[M];
ll e_sum,head[M];
void addedge(ll x,ll y,ll z)
{
    e[e_sum].next = head[x];
    e[e_sum].to = y;
    e[e_sum].cost = z;
    head[x] = e_sum++;
}
void dij(ll start,ll dist[]){
    priority_queue<pair<ll, ll>> q; //优先队列，默认是first最小的排在队尾，然后我们top pop都是队首，所以相当于first最大的先出来。因此我们把first也就是距离取负push进优先队列。
    bool vis[N];
    memset(vis,false,sizeof(vis));
    
    dist[start] = 0;
    q.push(make_pair(-dist[0], start));
    while (!q.empty()){
        ll now = q.top().second;
        q.pop();
        if (!vis[now]){ //由于同一个点只能进优先队列一次，因此我们在松弛前先进行判断
            vis[now] = true;
            for (ll i = head[now]; i != -1; i=e[i].next){
                ll u = e[i].to;
                ll h = e[i].cost;
                if (dist[now] + h < dist[u]){
                    dist[u] = dist[now] + h;
                    q.push(make_pair(-dist[u], u));
                }
            }
        }
    }
}
void spfa(ll start,ll dist[]){
    queue <ll>q;
    bool vis[N];
    memset(vis,false,sizeof(vis));
    
    dist[start] = 0;
    q.push(start);
    vis[start] = true;
    while (!q.empty()){
        ll now = q.front();
        q.pop();
        for (ll i = head[now]; i != -1; i=e[i].next){
            ll u = e[i].to;
            ll h = e[i].cost;
            if (dist[now]+h<dist[u]){
                dist[u] = dist[now] + h;
                if (vis[u]==false){ //如果不在队列中，就进队
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
        vis[now] = false;
    }
}
int main() {
//    priority_queue<pair<ll, ll>> q;
//    q.push(make_pair(1,4));
//    q.push(make_pair(5,3000));
//    q.push(make_pair(3,2));
//    cout << q.top().first << " " << q.top().second << endl;
    ll n,m,x,y,z;//f1[N],fn[N];
    cin >> n >> m;
    e_sum = 0;
    memset(head,-1,sizeof(head));
    ll cnt,id;
    rep (i,1,m){
        scanf("%lld%lld%lld",&x,&y,&z);
        addedge(x,y,2*z);
        addedge(y,x,2*z);
    }

    rep (i,1,n){
        scanf("%lld",&a[i]);
        addedge(n+1,i,a[i]);
        addedge(i,n+1,a[i]);
    }

    for (int i=1;i<=n+1;i++)
        dis[i] = 1e18;
//    spfa(n+1,dis);
    dij(n+1, dis);
    rep (i,1,n)
        cout << dis[i] << " ";
    cout << endl;
    return 0;
}
