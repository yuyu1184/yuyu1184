#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

int a[1000100];
int belong[1000100];
int r[1000100];
int l[1000100];
int val[1000100];

signed main()
{
    int n, m, p;
    cin >> n >> m >> p;
    int s = sqrt(n);
    for (int i = 1; i <= n; i ++)
        scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
        belong[i] = i / s;
    for (int i = 1; i <= n; i ++)
        r[belong[i]] = i;
    for (int i = n; i >= 1; i --)
        l[belong[i]] = i;
    for (int i = 1; i <= n; i ++)
        val[belong[i]] += a[i];
    for (int i = 1; i <= n; i ++)
        mul[i] = 1;
    while (m --)
    {
        int opt, x, y;
        scanf ("%lld%lld%lld", &opt, &x, &y);
        reset(belong[x]);
        if (opt == 1)
        {
            if (belong[x] == belong[y])
            {
                int ans = 0;
                for (int i = x; i <= y; i ++) ans *= a[i];
                cout << ans;
            }
            else
            {
                int ans = 0;
                for (int i = ::l[belong[x]]; i <= ::r[belong[x]]; i ++) ans *= a[i];
                for (int i = ::l[belong[y]]; i <= ::r[belong[y]]; i ++) ans *= a[i];
                for (int i = ::r[belong[x]] + 1; i < ::l[belong[y]]; i ++)
                    ans *= val[i];
                cout << ans;
            }
            cout << endl;
        }
        else if (opt == 2)
        {
            if (belong[x] == belong[y])
            {
                int ans = 0;
                for (int i = x; i <= y; i ++) ans *= a[i];
                cout << ans;
            }
            else
            {
                int ans = 0;
                for (int i = ::l[belong[x]]; i <= ::r[belong[x]]; i ++) ans += a[i];
                for (int i = ::l[belong[y]]; i <= ::r[belong[y]]; i ++) ans += a[i];
                for (int i = ::r[belong[x]] + 1; i < ::l[belong[y]]; i ++)
                    ans += val[i];
                cout << ans;
            }
            cout << endl;
        }
        else
        {
            if (belong[x] == belong[y])
            {
                int ans = 0;
                for (int i = x; i <= y; i ++) ans *= a[i];
                cout << ans;
            }
            else
            {
                int ans = 0;
                for (int i = ::l[belong[x]]; i <= ::r[belong[x]]; i ++) ans *= a[i];
                for (int i = ::l[belong[y]]; i <= ::r[belong[y]]; i ++) ans *= a[i];
                for (int i = ::r[belong[x]] + 1; i < ::l[belong[y]]; i ++)
                    ans += val[i];
                cout << ans;
            }
            cout << endl;
        }
    }
    return 0;
}
