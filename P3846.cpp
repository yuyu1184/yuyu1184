#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;

int ksc(int x, int y,int z)
{
    if (! y) return 0;
    int ans = ksc(x, y >> 1, z);
    ans = (ans + ans) % z;
    if (y & 1) ans = (ans + x) % z;
    return ans;
}

int ksm(int x, int y, int z)
{
    if (! y) return 1;
    int ans = ksm(x, y >> 1, z);
    ans = ksc(ans, ans, z);
    if (y & 1) ans = ksc(ans, x, z);
    return ans;
}

int solve(int a, int b, int p)
{
    int s = (int) (sqrt(p) + 0.01);
    set <int> se;
    int ans = 1;
    for(int i = 0; i < s; i ++)
    {
        se.insert(ans);
        ans = 1LL * ans * a % p;
    }
    ans = ksm(ans, p - 2, p);
    int c = b;
    for (int i = 0; i < p - 1; i += s)
    {
        if (se.count(c) != 0)
        {
            int v = ksm(a, i, p);
            while (v != b)
            {
                v = 1LL * v * a % p;
                i ++;
            }
            return i;
        }
        c = 1LL * c * ans % p;
    }
    return -1;
}

signed main()
{
    int p, b, n;
    cin >> p >> b >> n;
    int an = solve(b, n, p);
    if (~ an) cout << solve(b, n, p) << endl;
    else cout << "no solution" << endl;
    return 0;
}
