#include <iostream>
#include <cstdio>

using namespace std;

int ans = 0x3f3f3f3f;
int fa[1000010];

int F(int x, int &cnt)
{
    cnt ++;
    if (fa[x] == x) return x;
    else return(fa[x], cnt);
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 1; i <= n; i ++)
    {
        int cnt = 0, f;
        cin >> f;
        if (F(f, cnt) == i) ans = min(ans, cnt);
        else fa[i] = f;
    }
    cout << ans;
    return 0;
}
