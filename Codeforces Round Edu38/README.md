# Codeforces Round #462

[传送门](http://codeforces.com/contest/938)

ABC题还算顺利，D题图论的模型很好建立，增加一个源点求一个单源最短路径即可。但是比赛的时候由于我用的是SPFA，所以一直被卡最后一个点而TLE，现在简单做一个这两个我常用的最短路径算法的对比。

## Dijkstra VS SPFA

> Dijkstra算法思路的核心就是每次找一个未被标记的距离最短的点来松弛和它相连的边，用STL的优先队列实现堆优化后，时间复杂度是O((V+E)lgv)

> SPFA是BellmanFord的一种优化，根据论文的证明时间复杂度[大概]是O(kE)。其思路是：每次对队首的点进行松弛相连的边，只要松弛成功，判断该相连的点是否在队列中，如果不在就入队。因此我们看到一个很明显的区别就在于SPFA的队列一个点可以进队多次。

* Dijkstra是每次确定了到一个点的最短距离，再用该点更新到其它点的距离。不能处理有负边的图。因为Dijkstra每次选的是当前能连到的边中权值最小的，在正权图中这种贪心是对的，但是在负权图中就不是这样了。如下图，1——>2权值为2，1——>3权值为3，3——>2权值为-2，求1到2的最短路径时，Dijkstra就会选择权为2的1——>2，但实际上1——>3——>2才是最优的结果。其路径长为1.
![Screen 2018-02-17 AM12.29.24.jpg](https://i.loli.net/2018/02/17/5a87b01a733d0.jpg)

* SPFA是用双端队列，每次取出队头，来更新距离，它之后可能还会入队。它是一种动态逼近法，因为每次松弛距离都会减小，所以松弛一定会有结束的。如果一个点入队超过n次就是存在负环。

* SPFA可以判断负环：判断一个点是否进队的次数>n(n为所有节点的个数)。如果包含负环，则意味着最短路径不存在。因为只要在负权回路上不断兜圈子，所得的最短路长度可以任意小。

* SPFA可以被卡专门造的数据，例如这篇博客的[SPFA-killer](http://blog.csdn.net/yfzcsc/article/details/77623365)


总结：
Dijkstra的稳定性好，在稠密图更快，但不能解决有负权边的问题。SPFA可以解决负权边、判断负环是否存在，在稀疏图更快，但是稳定性差、比赛如果不是随机数据可能被卡掉。

另附Dijlstra模板与SPFA模板，调用的时候例如`for (int i=1;i<=n;i++) dis[i] = 1e18; dij(1, dis);`：就可以计算从顶点1到所有点的距离保存在dis数组中。

```
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
```

```
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
```

