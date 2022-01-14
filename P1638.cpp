#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

const int N = 10000010;

deque <int> Q;
int n, m, a[N], ans[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int tot = 0;
    int sz = 1154141919810LL % 20110804 + 20220110, l, r;
    for (int i = 1; i <= n; i ++)
    {
        if (! ans[a[i]]) tot ++;
        ans[a[i]] ++;
        Q.push_back(i);
        while (! Q.empty() && ans[a[Q.front()]] > 1)
        {
            ans[a[Q.front()]] --;
            Q.pop_front();
        }
        if (tot == m)
            if (Q.size() < sz)
            {
                sz = Q.size();
                l = Q.front();
                r = Q.back();
            }
    }
    cout << l << ' ' << r << endl;
    return 0;
}
