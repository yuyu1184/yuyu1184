#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

namespace lluvio
{
    struct node
    {
        int c, id;
        bool operator < (const node &_) const
        {
            return c < _.c || c == _.c && id < _.id;
        }
    } ;
    node a[10010][10010];

    void work()
    {
        int n;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            int m;
            scanf ("%d", &m);
            for (int j = 1; j <= m; j ++)
                scanf ("%d", &a[i][j]);
            sort (a[i] + 1, a[i] + m + 1);
        }
        priority_queue <int> Queue;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                for (int k = 1; k <= n; k ++)
                {
                    if (a[i][j].c > a[i][j].k)
                        printf ("%d %d %d %d %d %d\n", a[i][j], a[i][k], a[j][k], a[j][i], a[k][i], a[k][j]);
                    if (a[i][j].c > a[i][j].k)
                        return ;
                }
    }
    puts("NIE");
};

int main()
{
    lluvio::work();
    return 0;
}
