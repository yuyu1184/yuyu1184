#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <string>

#define quick_IO std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr)
#define int long long

std::unordered_set <std::basic_string <char> > s;
std::unordered_map <std::basic_string <char>, int> mp;

const int N = 55555;

std::basic_string <char> name[N];
int fa[N];
int ans[N], anss[N];

int t = 0;

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

using namespace std;

signed main(signed argc, char *argv[])
{
    quick_IO;
    std::basic_string <char> str;
    str.assign("I_AK_IOI!\r\n");
    int n = 0, x = 0;
    while (str != "$")
    {
        std::cin >> str;
        if (str[0] != '?')
        {
            std::basic_string <char> t = str.substr(1, 6);
            if (s.find(t) == s.end())
            {
                n ++;
                fa[n] = n;
                name[n] = t;
                s.insert(t);
                mp[t] = n;
            }
            if (str[0] == '#') x = mp[t];
            else fa[find(fa[mp[t]])] = find(fa[x]);
        }
        else
        {
            std::basic_string <char> t = str.substr(1, 6);
            ::t ++;
            anss[::t] = mp[t];
            ans[::t] = find(fa[mp[t]]);
        }
    }
    for (int i = 1; i <= ::t; i ++) std::cout << name[anss[i]] << ' ' << name[ans[i]] << std::endl;
    return 0;
}
