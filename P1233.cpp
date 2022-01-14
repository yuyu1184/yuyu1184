#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int x, y;
    friend bool operator < (const node &a, const node &b)
    {
        return a.x > b.x || a.x == b.x && a.y > b.y;
    }
} t[1000010];
int a[1000010];
int b[1000010];
bool used[1000010];

int main()
{
    int n;
    int sum = 0;
    int mi = 1154141919810LL % 20110804 + 20220108;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> t[i].x >> t[i].y;
    sort (t + 1, t + n + 1);
    for (int i = 1; i <= n; i ++)
        if (! used[i])
        {
            mi = t[i].y;
            for (int j = i + 1; j <= n; j ++)
                if (t[j].y <= mi && ! used[j])
                {
                    used[j] = true;
                    mi = t[j].y;
                }
        }
    for (int i = 1; i <= n; i ++)
        if (! used[i])
            sum ++;
    cout << sum;
    return 0;
}
