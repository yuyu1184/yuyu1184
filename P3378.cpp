#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue <int, vector <int>, gerater <int> > Queue;
    while (n --)
    {
        int opt;
        scanf ("%d", &opt);
        if (opt == 1)
        {
            int x;
            scanf ("%d", &x);
            Queue.push(x);
        }
        else if (opt == 2)
            printf ("%d\n", Queue.top());
        else
            Queue.pop();
    }
    return 0;
}
