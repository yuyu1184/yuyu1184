#include <iostream>
#include <cstdio>
using namespace std;

const int N = 16;
int a[N][N];
int ans[N];
bool vis[N], flag = false;
int n, k;

void dfs(int i = 1, int s = 0)
{
    if (flag) return ;
    if (s > k) return ;
    if (i == n + 1 && s == k)
    {
        for (int j = 1; j <= n; j ++) cout << ans[j] << ' ';
        cout << endl;
        flag = true;
        return ;
    }
    else
    {
        for (int j = 1; j <= n; j ++)
            if (! vis[j])
            {
                vis[j] = true;
                ans[i] = j;
                dfs(i + 1, s + j * a[n][i]);
                vis[j] = false;
            }
    }
}

void init_C()
{
    for (int i = 1; i <= 15; i ++)
        for (int j = 1; j <= i; j ++)
            if (j == 1 || j == i) a[i][j] = 1;
            else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
}

int main()
{
    cin >> n >> k;
    init_C();
    dfs(1, 0);
    return 0;
}
