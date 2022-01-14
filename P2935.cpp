#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long l[1000010], mp[2010][2010];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
        cin >> l[i];
    memset (mp, 0x3f, sizeof mp);
    for (int i = 1; i <= n; i ++)
        mp[i][i] = 0;
    while (k --)
    {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        mp[x][y] = mp[y][x] = min(mp[x][y], z);
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
    long long ans = 0x3f3f3f3f3f3f3f3f;
    long long id = 0;
    for (int i = 1; i <= n; i ++)
    {
        long long A = 0;
        for (int o = 1; o <= m; o ++)
            A += mp[l[o]][i];
        if (ans > A)
            ans = A, id = i;
    }
    cout << id;
    return 0;
}
