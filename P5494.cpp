#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200010;
typedef long long ll;

struct Node
{
    int l, r;
    ll val;

    bool operator == (const Node &_) const
    {
        return _.l == l && _.r == r && _.val == val;
    }
} sgt[maxn << 6];

int cnt, root[maxn];

inline void pushup(int k)
{
    sgt[k].val = sgt[sgt[k].l].val + sgt[sgt[k].r].val;
}

void modify(int l, int r, int &k, int p, int x)
{
    if (!k)
        k = ++cnt;
    sgt[k].val += x;
    if (l == r)
        return ;
    int m = (l + r) >> 1;
    if (p <= m)
        modify(l, m, sgt[k].l, p, x);
    else
        modify(m + 1, r, sgt[k].r, p, x);
}

void merge(int &x, int y)
{
    if (!x || !y)
        x |= y;
    else
    {
        sgt[x].val += sgt[y].val;
        merge(sgt[x].l, sgt[y].l);
        merge(sgt[x].r, sgt[y].r);
    }
}

int split(int l, int r, int &k, int x, int y)
{
    int n =  ++ cnt;
    if (x <= l && y >= r)
    {
        sgt[n] = sgt[k];
        k = 0;
    }
    else
    {
        int m = (l + r) >> 1;
        if (x <= m)
            sgt[n].l = split(l, m, sgt[k].l, x, y);
        if (y > m)
            sgt[n].r = split(m + 1, r, sgt[k].r, x, y);
        pushup(k);
        pushup(n);
    }
    return n;
}

ll query(int l, int r, int k, int x, int y)
{
    if (x <= l && y >= r)
        return sgt[k].val;
    int m = (l + r) >> 1;
    ll sum = 0;
    if (x <= m)
        sum += query(l, m, sgt[k].l, x, y);
    if (y > m)
        sum += query(m + 1, r, sgt[k].r, x, y);
    return sum;
}

ll query(int l, int r, int k, int kth)
{
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    if (kth <= sgt[sgt[k].l].val)
        return query(l, m, sgt[k].l, kth);
    else
        return query(m + 1, r, sgt[k].r, kth - sgt[sgt[k].l].val);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        scanf ("%d", &x);
        modify(1, n, root[1], i, x);
    }
    int last = -1;
    while (m --)
    {
        int opt, x, y, z;
        scanf ("%d%d%d", &opt, &x, &y);
        int od;
        switch (opt)
        {
            case 0:
                cin >> z;
                od = cnt;
                root[++last] = split(1, n, root[x], y, z);
                break;
            case 1:
                merge(root[x], root[y]);
                break;
            case 2:
                cin >> z;
                modify(1, n, root[x], z, y);
                break;
            case 3:
                cin >> z;
                cout << query(1, n, root[x], y, z) << endl;
                break;
            case 4:
                if (y > sgt[root[x]].val)
                    puts("-1");
                else
                    cout << query(1, n, root[x], y) << endl;
        }
    }
    return 0;
}
