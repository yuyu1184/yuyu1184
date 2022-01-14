#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000010;
int a[N], fa[N];

inline int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, m;
    while (scanf ("%d%d", &n, &m) == 3)
    {
        for (int i = 1; i <= n; i ++) fa[i] = i;
        while (m --)
        {
            int a, b;
            cin >> a >> b;
            int ta = find(a), tb = find(b);
            fa[ta] = tb;
        }
        int L = 0;
        for (int i = 1; i <= n; i ++)
            a[++ L] = find(i);
        cout << unique(a + 1, a + n + 1) - a << endl;
    }
    return 0;
}
