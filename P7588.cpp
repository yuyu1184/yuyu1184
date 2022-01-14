#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

bitset <100000010> vis;

const int N = 8000013;

int cnt[N], t[N];
int ccnt = 0;

int check(int x)
{
    int res = 0;
    while (x)
    {
        res += (x % 10);
        x /= 10;
    }
    if (vis[res]) return false;
    else return true;
}

void init(const int Maxn)
{
    for (int i = 2; i <= Maxn; i ++)
    {
        if (! vis[i]) t[++ ccnt] = i;
        for (int j = 1; j <= ccnt && t[j] * i <= Maxn; j ++)
        {
            vis[t[j] * i] = true;
            if (i % t[j]) continue;
        }
    }
    for (int i = 1; i <= ccnt; i ++)
    {
        if (check(t[i])) cnt[i] = 1;
        cnt[i] += cnt[i - 1];
    }
}

int main()
{
    init(1e8 + 7);
    int T;
    cin >> T;
    while (T --)
    {
        int l, r;
        cin >> l >> r;
        int L = lower_bound(t + 1, t + ccnt + 1, l) - t;
        int R = lower_bound(t + 1, t + ccnt + 1, r) - t;
        if (t[R] > r) R --;
        cout << cnt[R] - cnt[L - 1] << endl;
    }
    return 0;
}
