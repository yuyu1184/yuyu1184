#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define Quick_IO std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
#define int long long

inline int find(int u)
{
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

#define r_v() std::cout << "No Answer" << std::endl; exit(0);
#define i_f() for (int i = 1; i <= n; i ++) std::cin >> a[i];
#define p_w() for (int i = 1; i <= m; i ++)\
{\
    int u, v, w;\
    std::cin >> u >> v >> w;\
    v.push_back({u, v, w});\
}
#define s_p() std::sort (v.begin(), v.end());
#define r_e() int cnt = 0, tot = 0;
#define p_e() for (int i = 0; i < (int) v.size(); i ++)\
    if (find(v[i].u) - find(v[i].v))\
    {\
        fa[find(v[i].u)] = find(v[i].v);\
        cnt ++;\
        tot += v[i].w;\
    }\
std::cout << tot << std::endl;

signed main(signed argc, char *argv[])
{
    Quick_IO;
    int n, m, k;
    cin >> n >> m >> k;
    if (k > n) r_v();
    i_f();
    p_w();
    s_p();
    r_e();
    p_e();
    return 0;
}
