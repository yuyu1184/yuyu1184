#include <iostream>
#include <cstdio>

using namespace std;

int fa[1000010];
int E, h[1000010], e[1000010], ne[1000010];

void add(int a, int b)
{
    e[E] = b;
    ne[E] = h[a];
    h[a] = E ++;
}

inline int find(int a)
{
    return fa[a] == a ? a : fa[a] = find(fa[a]);
}

int main()
{
    memset (h, -1, sizeof h);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int now = 0;
    for (int i = n; i; i --)
    {
        now ++;
        vis[a[i]] = true;
        for (int j = h[a[i]]; ~j; j = ne[j])
        {
            int v = e[j];
            if (vis[v])
            {
                int r1, r2;
                r1 = find(a[i]), r2 = find(v);
                if (r1 != r2)
                {
                    fa[r1] = r2;
                    now --;
                }
            }
        }
        if (now == 1)
            ans[i] = true;
    }
    for (int i = 1; i <= n; i ++)
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    return 0;
}
