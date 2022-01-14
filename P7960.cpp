#include <iostream>
#include <cstdio>

using namespace std;

bool vis[22222222];
int ne[22222222];

bool request(int x)
{
    while (x)
    {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int main()
{
    for (int i = 7; i <= 10333333; i ++)
        if (request(i))
            for (int j = i; j <= 10333333; j += i)
                vis[j] = true;
    int l_point = 0;
    for (int i = 0; i <= 10333333; i ++)
    {
        if (! vis[i])
        {
            for (int j = i - 1; j >= l_point; j --)
                ne[j] = i;
            l_point = i;
        }
    }
    int T;
    cin >> T;
    while (T --)
    {
        int u;
        scanf ("%d", &u);
        if (vis[u]) puts("-1");
        else printf ("%d\n", ne[u]);
    }
    return 0;
}
    