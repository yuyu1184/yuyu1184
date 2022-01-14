#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100010];
int dist[2020][2021];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> dist[i][j];
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    long long ans = 0;
    for (int i = 2; i <= m; i ++)
        ans += dist[a[i - 1]][a[i]];
    cout << ans;
    return 0;
}
