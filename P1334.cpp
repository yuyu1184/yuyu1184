#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>

#define int long long

using namespace std;

int t;
inline int R()
{
    cin >> t;
    return t;
}

int main()
{
    int n = R();
    priority_queue <int, vector <int>, greater <int> > q;
    for (int i = 1; i <= n; i ++) q.push(R());
    int ans = 0;
    while (q.size() > 1)
    {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans;
    return 0;
}
