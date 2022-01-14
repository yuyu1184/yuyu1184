#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map <int, int> fa;

inline int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = -m; i <= n; i ++) fa[i] = i;
    while (p --)
    {
        int a, b;
        cin >> a >> b;
        int ta = find(a);
        int tb = find(b);
        if (ta != tb)
            fa[ta] = tb;
    }
    while (q --)
    {
        int a, b;
        cin >> a >> b;
        int ta = find(a);
        int tb = find(b);
        if (ta != tb)
            fa[ta] = tb;
    }
    int cnt = 0, Cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (find(i) == find(1))
            cnt ++;
    for (int i = -m; i <= -1; i ++)
        if (find(i) == find(-1))
            Cnt ++;
    cout << min(cnt, Cnt);
    return 0;
}
