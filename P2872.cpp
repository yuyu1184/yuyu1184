#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;

int n, m;
int tot = 0;
int fat[N];
double ans = 0.000000, x[N], y[N];

struct e
{
    int next, to;
    double dis;
} edge[N * N];

bool cmp(e x, e y)
{
    return x.dis < y.dis;
}

inline double dist(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void add(int from, int to, double dist)
{
    edge[++ tot].next = from;
    edge[tot].to = to;
    edge[tot].dis = dist;
}

inline int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void fk()
{
    int f1, f2, k = 0;
    for (int i = 1; i <= n; i ++)
        fat[i] = i;
    for (int i = 1; i <= tot; i ++)
    {
        f1 = find(edge[i].next);
        f2 = find(edge[i].to);
        if (f1 != f2)
        {
            fat[f1] = f2;
            ans += edge[i].dis;
            k ++;
            if (k == n - 1)
                break;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
    while (m --)
    {
        int x, y;
        cin >> x >> y;
        add(x, y, 0);
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j < i; j ++)
            add(i, j, dist(x[i], x[j], y[i], y[j]));
    sort (edge + 1, edge + tot + 1, cmp);
    fk();
    printf ("%.2lf\n", ans);
    return 0;
}
