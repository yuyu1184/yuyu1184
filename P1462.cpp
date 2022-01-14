#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define int long long

using namespace std;

struct Posit
{
    int x, id;
    Posit () {};
    Posit (int x_x, int id_x)
    {
        x = x_x, id = id_x;
    }
    friend bool operator < (const Posit &XX, const Posit &YY)
    {
        return XX.x < YY.x;
    }
} pos[1000010];

//struct node
//{
//    int v, w, ne;
//} ;

int n, m, k;

int e[1000010], ne[1000010], w[1000010], h[1000010], E = 0;
bool vis[1000010];
int dist[1000010];
bool nv[1000010];

bool spfa(int u)
{
    queue <int> Q;
    Q.push(u);
    memset (vis, false, sizeof vis);
    vis[u] = true;
    memset (dist, 0x3f, sizeof dist);
    dist[u] = 0;
    while (! Q.empty())
    {
        auto f = Q.front();
        Q.pop();
        vis[f] = false;
        for (int i = h[f]; ~i; i = ne[i])
        {
            int v = e[i];
            if (dist[v] > dist[f] + w[i] && ! nv[v])
            {
                dist[v] = dist[f] + w[i];
                if (! vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return dist[n] <= k;
}

void add(int a, int b, int c)
{
    e[E] = b;
    ne[E] = h[a];
    w[E] = c;
    h[a] = E ++;
}

signed main()
{
    memset (h, -1, sizeof h);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
    {
        pos[i].id = i;
        cin >> pos[i].x;
    }
    sort (pos + 1, pos + n + 1);
    while (m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    if (! spfa(1))
    {
        cout << "AFK";
        return 0;
    }
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = l + r >> 1;
        memset (nv, false, sizeof nv);
        for (int i = mid + 1; i <= n; i ++)
            nv[pos[i].id] = true;
        if (spfa(1))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << pos[l].x;
    return 0;
}
