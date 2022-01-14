#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 210;

pair <int, int> p[N];

int pre[N];
bool vis[N];
double w[N], d[N];
int h[N], ne[N], e[N], E;

void add(int a, int b, double c)
{
    e[E] = b;
    w[E] = c;
    ne[E] = h[a];
    h[a] = E ++;
}

void spfa(int s, int f, int t)
{
    memset(d, INF, sizeof d);
    queue <int> Q;
    Q.push(s);
    vis[s] = true;
    d[s] = 0;
    while (! Q.empty())
    {
        int g = Q.front();
        Q.pop();
        vis[g] = false;
        for (int i = h[g]; ~i; i = ne[i])
        {
            int v = e[i];
            if ((f == g && t == v) || (f == v && t == g)) continue;
            if (d[v] > d[g] + w[i])
            {
                d[v] = d[g] + w[i];
                if (! (~f) && ! (~t)) pre[v] = g;
                if (vis[v]) continue;
                Q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main()
{
    E = 0;
    memset (h, -1, sizeof h);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> p[i].first >> p[i].second;
    while (m --)
    {
        int a, b;
        cin >> a >> b;
        double c = sqrt(pow(p[a].second - p[a].first, 2) + pow(p[b].second - p[b].first, 2));
        add(a, b, c);
        add(b, a, c);
    }
    spfa(1, -1, -1);
    int t = n;
    double ans = INF * 1.02;
    while (pre[t])
    {
        memset (vis, false, sizeof vis);
        int tmp = pre[t];
        spfa(1, tmp, t);
        ans = min(ans, d[n]);
        t = tmp;
    }
    if (ans == INF) cout << -1;
    else printf ("%.2lf\n", ans);
    return 0;
}
