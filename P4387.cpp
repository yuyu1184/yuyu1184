#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int a[1000010], b[1000010];

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        int n;
        cin >> n;
        int t2 = 1;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= n; i ++) cin >> b[i];
        stack <int> st;
        for (int i = 1; i <= n; i ++)
        {
            st.push(a[i]);
            while (! st.empty() && st.top() == b[t2] && t2 <= n)
            {
                st.pop();
                t2 ++;
            }
        }
        if (! st.empty()) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}

