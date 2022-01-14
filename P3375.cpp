#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000010];
char p[1000010];
int  ne[1000010];

int main()
{
    int n, m;
    scanf ("%s%s", s + 1, p + 1);
    n = strlen(p + 1);
    m = strlen(s + 1);
    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j ++;
        ne[i] = j;
    }
    int cnt = 0;
    for (int i = 1, j = 0; i <= m ; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j ++;
        if (j == n)
        {
            printf("%d\n", i - n + 1);
            j = ne[j];
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << ne[i] << ' ';
    return 0;
}

