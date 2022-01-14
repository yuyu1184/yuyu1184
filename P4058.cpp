#include <iostream>
#include <cstdio>

#define int unsigned long long

using namespace std;

int h[1000010], a[1000010];
int hn[1000010];
int n, s, l;

bool ch(int x)
{
    for (signed i = 1; i <= n; i ++)
        hn[i] = h[i] + x * a[i];
    int sum = 0;
    for (signed i = 1; i <= n; i ++)
        if (hn[i] >= l)
            sum += hn[i];
    return sum >= s;
}

signed main()
{
    cin >> n >> s >> l;
    for (signed i = 1; i <= n; i ++)
        cin >> h[i];
    for (signed i = 1; i <= n; i ++)
        cin >> a[i];
    if (ch(0))
        cout << 0 << endl;
    else
    {
        int l = 1, r = (int) 5E18;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (ch(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}

