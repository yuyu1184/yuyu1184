#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int x, y, t;
    friend bool operator < (const node & _1, const node & _2)
    {
        return _1.t < _2.t;
    }
} ;

int fa[1000010];

inline int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) fa[i] = i;
    vector <node> Node;
    for (int i = 1; i <= m; i ++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        node N;
        N.x = x;
        N.y = y;
        N.t = t;
        Node.push_back(N);
    }
    sort (Node.begin(), Node.end());
    int id = -1;
    for (int i = 0; i < m; i ++)
    {
        int x = Node.at(i).x;
        int y = Node.at(i).y;
        int t = Node.at(i).t;
        int ta = find(x), tb = find(y);
        fa[ta] = tb;
        bool flag = true;
        for (int i = 2; i <= n; i ++)
            if (find(i) != find(1))
            {
                flag = false;
                break;
            }
        if (flag)
        {
            id = t;
            break;
        }
    }
    cout << id << endl;
    return 0;
}
