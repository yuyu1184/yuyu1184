#include <iostream>
#include <cstdio>

using namespace std;

int f[10010];
int t[10010];
int bj[10010];
int h[10010];
int ans;

inline int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

void fun(int x, int y)
{
    int z = find(x);
    if (z != y)
    {
        f[y] = z;
        t[z] += t[y];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        t[i] = 1;
        f[i] = i;
    }
    while (m --)
    {
        int a, b;
        cin >> a >> b;
        int x1 = find(a);
        int x2 = find(b);
        if (x1 != x2)
        {
            if (h[a])
                fun(h[a], x2);
            if (h[b])
                fun(h[b], x1);
            h[a] = x2;
            h[b] = x1;
        }
        else
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        int q = find(i);
        if (! bj[q])
        {
            int ql = find(h[i]);
            bj[q] = 1;
            bj[ql] = 1;
            ans += min(t[q], t[ql]);
        }
    }
    cout << ans << endl;
    return 0;
}
