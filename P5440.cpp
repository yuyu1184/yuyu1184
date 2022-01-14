#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100000010;
int t[N];
bool vis[N];
int cnt = 0;
int mon[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void init(const int Maxn)
{
    vis[1] = true;
    for (int i = 2; i <= Maxn; i ++)
    {
        if (! vis[i])
            t[++ cnt] = i;
        for (int j = 1; j <= cnt && t[j] * i <= Maxn; j ++)
        {
            vis[t[j] * i] = true;
            if (i % t[j])
                continue;
        }
    }
}

bool g(int y)
{
    if (y % 400 == 0)
        return true;
    if (y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}

int f(int y, int m)
{
    int days = mon[m];
    if (m == 2 && g(y))
        days ++;
    return days;
}

bool nch(int y, int m, int d, string s)
{
    if (s[0] != y / 1000 + '0' && s[0] != '-')
        return false;
    y %= 1000;
    if (s[1] != y / 100 + '0' && s[1] != '-')
        return false;
    y %= 100;
    if (s[2] != y / 10 + '0' && s[2] != '-')
        return false;
    y %= 10;
    if (s[3] != y / 1 + '0' && s[3] != '-')
        return false;
    y %= 1;
    if (s[4] != m / 10 + '0' && s[4] != '-')
        return false;
    m %= 10;
    if (s[5] != m / 1 + '0' && s[5] != '-')
        return false;
    m %= 1;
    if (s[6] != d / 10 + '0' && s[6] != '-')
        return false;
    d %= 10;
    if (s[7] != d / 1 + '0' && s[7] != '-')
        return false;
    d %= 1;
    return true;
}

bool check(int y, int m, int d, string s)
{
    if (nch(y, m, d, s))
        return false;
    int c1 = d, c2 = m * 100 + d, c3 = y * 10000 + m * 100 + d;
    if (! vis[c1] && ! vis[c2] && ! vis[c3])
        return true;
    else
        return false;
}

int print(string s)
{
    int cnt = 0;
    for (int y = 0; y <= 9999; y ++)
        for (int m = 1; m <= 12; m ++)
            for (int d = 1; d <= f(y, m); d ++)
                if (check(y, m, d, s))
                    cnt ++;
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    init(100000003);
    while (T --)
    {
        string s;
        cin >> s;
        cout << print(s) << endl;
    }
    return 0;
}
