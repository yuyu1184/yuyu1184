#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = N * N;
const int INF = 0x3f3f3f3f;

int n, s, t, edge_sum;
int dis[N], head[N];
bool vis[N];

struct Edge
{
    int next, to, dis;
} edge[M << 1];

void addedge(int from, int to, int dis)
{
    edge[++ edge_sum].next = head[from];
    edge[edge_sum].to = to;
    edge[edge_sum].dis = dis;
    head[from] = edge_sum;
}

struct node
{
    int u, v;
    bool operator < (const node &rhs) const
    {
        return v > rhs.v;
    }
};

priority_queue <node> q;

node make_node(int x, int y)
{
    node t;
    t.u = x;
    t.v = y;
    return t;
}

void dijkstra()
{
    for (int i = 1; i <= n; i ++)
        dis[i] = INF;
    dis[s] = 0;
    q.push(make_node(s, dis[s]));
    while (q.size())
    {
        node t = q.top();
        q.pop();
        int u = t.u;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int j = head[u]; ~j; j = edge[j].next)
        {
            if (dis[u] + edge[j].dis < dis[edge[j].to])
                dis[edge[j].to] = dis[u] + edge[j].dis;
            if (! vis[edge[j].to])
                q.push(make_node(edge[j].to, dis[edge[j].to]));
        }
    }
}

int main()
{
    memset(head, -1, sizeof head);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i ++)
    {
        int x, y;
        scanf("%d", &x);
        if (x == 0)
            continue ;
        scanf("%d", &y);
        addedge(i, y, 0);
        for (int j = 2; j <= x; j ++)
        {
            scanf("%d", &y);
            addedge(i, y, 1);
        }
    }
    dijkstra();
    if (dis[t] == INF)
        cout << -1;
    else
        cout << dis[t];
    cout << endl;
    return 0;
}
