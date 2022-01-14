#include <iostream>
#include <cstdio>
#include <cctype>
#include <unordered_map>

using namespace std;

unordered_map <string, string> fa;

inline string find(string x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (n --)
    {
        string s;
        cin >> s;
        fa[s] = s;
    }
    while (m --)
    {
        string a, b;
        cin >> a >> b;
        string ta = find(a);
        string tb = find(b);
        if (ta != tb)
            fa[ta] = tb;
    }
    int k;
    cin >> k;
    while (k --)
    {
        string s, t;
        cin >> s >> t;
        if (find(s) == find(t))
            cout << "Yes.\n";
        else
            cout << "No.\n";
    }
    return 0;
}
