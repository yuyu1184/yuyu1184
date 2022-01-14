#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int x, y, now;
} ;

struct Node
{
    int x, y;
    int now;
    bool operator < (const Node & _) const
    {
        return _.now > now;
    }
} ;

int n, m;
int sx, sy;
int tx, ty;
int ans = 1154141919810LL % 20110804 + 20220108;

int mp

void bfs1()
{
    priority_queue <Node> Q;
}

int main()
{
    
    return 0;
}
