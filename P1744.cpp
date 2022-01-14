#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
} ;

double distance(const Point &pointX, const Point &pointY)
{
    int Xdist = pointX.x - pointY.x;
    int Ydist = pointX.y - pointY.y;
    double answer = sqrt(pow(Xdist, 2) + pow(Ydist, 2));
    return answer;
}

const int N = 1000010;
Point a[N];
int s[N << 1], e[N << 1];
double d[N << 1];
double dis[N << 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        double dist = distance(a[x], a[y]);
        s[i] = x;
        e[i] = y;
        d[i] = dist;
        s[i + m] = y;
        e[i + m] = x;
        d[i + m] = dist;
        //cout << dist << ' ' << i << endl;
    }
    //cout << "--------" << endl;
    m <<= 1;
    int start, end;
    cin >> start >> end;
    fill(dis + 1, dis + 2000016, 1e9 + 7);
    //cout << dis[3] << endl;
    //cout << "--------" << endl;
    dis[start] = 0;
    for (int i = 1; i < n; i ++)
        for (int j = 1; j <= m; j ++)
            dis[e[j]] = min(dis[e[j]], dis[s[j]] + d[j]);
    cout << endl ;
    printf ("%.2lf\n", dis[end]);
    return 0;
}
