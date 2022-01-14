#include <iostream>
#include <cstdio>

using namespace std;

bool mp[3333][3333];

int main()
{
    int n, m;
    cin >> n >> m;
    while (m --)
    {
        int x, y;
        cin >> x >> y;
        mp[x][y] = true;
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                mp[i][j] |= mp[i][k] & mp[k][j];
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        bool now = true;
        for (int j = 1; j <= n; j ++)
            if (i != j)
                now &= mp[i][j] | mp[j][i];
        ans += now;
    }
    cout << ans;
    return 0;
}
