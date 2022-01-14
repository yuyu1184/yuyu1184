#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int a[maxn + 10];

struct tree {
    int l, r;
    long long pre, add;
} t[4 * maxn + 10];

void bulid(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l == r) {
        t[p].pre = a[l];
        return;
    }
    int mid = l + r >> 1;
    bulid(p * 2, l, mid);
    bulid(p * 2 + 1, mid + 1, r);
    t[p].pre = t[p * 2].pre + t[p * 2 + 1].pre;
}

void spread(int p) {
    if (t[p].add) {
        t[p * 2].pre += t[p].add * (t[p * 2].r - t[p * 2].l + 1);
        t[p * 2 + 1].pre += t[p].add * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1);
        t[p * 2].add += t[p].add;
        t[p * 2 + 1].add += t[p].add;
        t[p].add = 0;
    }
}

void change(int p, int x, int y, int z) {
    if (x <= t[p].l && y >= t[p].r) {
        t[p].pre += (long long)z * (t[p].r - t[p].l + 1);
        t[p].add += z;
        return;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid)
        change(p * 2, x, y, z);
    if (y > mid)
        change(p * 2 + 1, x, y, z);
    t[p].pre = t[p * 2].pre + t[p * 2 + 1].pre;
}

long long ask(int p, int x, int y) {
    if (x <= t[p].l && y >= t[p].r)
        return t[p].pre;
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    long long ans = 0;
    if (x <= mid)
        ans += ask(p * 2, x, y);
    if (y > mid)
        ans += ask(p * 2 + 1, x, y);
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    bulid(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int q, x, y, z;
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d%d%d", &x, &y, &z);
            change(1, x, y, z);
        } else {
            scanf("%d%d", &x, &y);
            cout << ask(1, x, y) << endl;
        }
    }
    return 0;
}
