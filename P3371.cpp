#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 100100;
int d[N];
int head[N], nxt[N], to[N], w[N], E;

int n, m, s;

struct node
{
    int u, dis;
    bool operator > (const node & y) const
    {
        return dis > y.dis;
    }
} ;

void dijkstra(int s)
{
    priority_queue <node, vector <node>, greater <node> > q;
    for (int i = 1; i <= n; i ++ )
        d[i] = (1LL << 61) + 7;
    d[s] = 0;
    node t;
    t.u = s;
    t.dis = 0;
    q.push(t);
    while (! q.empty())
    {
        node t = q.top();
        q.pop();
        int u = t.u;
        if (t.dis > d[t.u])
            continue ;
        for (int i = head[u]; ~i; i = nxt[i])
        {
            long long v = to[i];
            if (d[u] + w[i] < d[v])
            {
                d[v] = d[u] + w[i];
                node qs;
                qs.dis = d[v];
                qs.u = v;
                q.push(qs);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << d[i] << ' ';
    cout << endl;
}

void add_edge(int a, int b, int c)
{
    to[E] = b;
    w[E] = c;
    nxt[E] = head[a];
    head[a] = E ++;
}

int main()
{
    memset (head, -1, sizeof head);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    dijkstra(s);
    return 0;
}
