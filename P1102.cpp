#include <iostream>
#include <cstdio>
#include <unordered_map>

#define int long long

using namespace std;

int a[1000010];

signed main ()
{
    int n, c;
    unordered_map <int, int> mp;
    cin >> n >> c;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) mp[a[i]] ++;
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans += mp[a[i] - c];
    cout << ans << endl;
    return 0;
}
