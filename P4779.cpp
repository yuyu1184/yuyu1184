#include <iostream>
#include <cstdio>
#include <cstring> // memset（） 
#include <queue>
using namespace std;

long long head[1000010];
long long nxt[1000010];
long long to[1000010];
long long d[1000010];
long long w[1000010];

long long n, m;

long long s;

int E;

struct node
{
    long long dis;
    long long u;
    bool operator < (const node &y) const
    {
        return dis > y.dis;
    }
};

priority_queue <node> q;

void dijkstra()
{
    for (int i = 1; i <= n; i ++)
    {
        d[i] = (1LL << 61) + 7;
    }
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
        {
            continue;
        }
        for (long long i = head[u]; i != -1; i = nxt[i])
        {
            long long v = to[i];
            if (d[u] + w[i] < d[v])
            {
                d[v] = d[u] + w[i];
                node qq;
                qq.dis = d[v];
                qq.u = v;
                q.push(qq);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << d[i] << ' ';
    cout << endl;
}

void add(int a, int b, int c)
{
    to[E] = b;
    w[E] = c;
    nxt[E] = head[a];
    head[a] = E;
    E ++;
}

int main()
{
    E = 0;
    memset(head, -1, sizeof head);
    scanf("%lld%lld", &n, &m);
    cin >> s;
    for (int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    dijkstra();;
    return 0;
}
