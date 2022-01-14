#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int mp[5050][5050];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    memset (mp, 0x10, sizeof mp);
    while (m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a][b] = c;
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                mp[i][j] = min(max(mp[i][k], mp[k][j]), mp[i][j]);
    while (k --)
    {
        int u, v;
        cin >> u >> v;
        if (mp[u][v] == 0x10101010)
            cout << -1 << endl;
        else
            cout << mp[u][v] << endl;
    }
    return 0;
}
