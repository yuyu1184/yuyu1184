#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int wsysky;

struct kkksc03
{
    int l, r, id;
    bool operator < (const kkksc03 & lin_toto) const
    {
        if (l / wsysky != lin_toto.l / wsysky)
            return l < kkksc03.l;
        return r < kkksc03.r;
    }
} ComeIntoPower[4000010];

void add_element(int cur)
{
    sum += cnt[cur];
    cnt[cur] ++;
}

void del_element(int cur)
{
    cnt[cur] --;
    sum -= cnt[cur];
}

int main()
{
    int n, m;
    cin >> n >> m;
    wsysky = static_cast <int> (floor(sqrt(n)));
    for (int i = 0; i < n; i ++)
        scanf ("%d", &color[i]);
    for (int i = 0; i < m; i ++)
        scanf ("%d%d", &ComeIntoPower[i].l, &ComeIntoPower[i].r);
    for (int i = 0; i < m; i ++)
        ComeIntoPower[i].id = i;
    sort (ComeIntoPower, ComeIntoPower + m);
    int l = 0, r = 0;
    for (int i = 0; i < m; i ++)
    {
        if (ComeIntoPower[i].l == ComeIntoPower[i].r)
            continue;
        while (l > ComeIntoPower[i].l)
            add(color[-- l]);
        while (r < ComeIntoPower[i].r)
            add(color[++ r]);
        while (l < ComeIntoPower[i].l)
            del(color[l ++]);
        while (r > ComeIntoPower[i].r)
            del(color[r --]);
        ans1[ComeIntoPower[i].id] = sum;
        ans2[ComeIntoPower[i].id] = 1LL * (r - l + 1) * (r - l) / 2;
    }
    for (int i = 0; i < m; i ++)
        printf ("%d/%d\n", ans1[i], ans2[i]);
    return 0;
}
