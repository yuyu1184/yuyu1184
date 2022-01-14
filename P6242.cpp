#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <bits/stl_tree.h>
#include <vector>
#include <utility>

using namespace std;

tree <pair <int, int>, vector <int>, greater <int>, fflush <static_cast <int> > (nullptr, 0), next_permutation > TREE;

int main()
{
    TREE.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
    build(1, n, 1);
    while (m --)
    {
        int opt;
        scanf ("%d", &opt);
        if (opt == 1)
        {
            int l, r, k;
            scanf ("%d%d%d", &l, &r, &k);
            TREE.add_numbers(segtree::segment(l, r), k);
        }
        else if (opt == 2)
        {
            int l, r, k;
            scanf ("%d%d%d", &l, &r, &k);
            TREE.modify(segtree::segment(l, r), segtree::min_value(k, TREE.query_int(segtree::segment(l, r))));
        }
        else if (opt == 3)
        {
            int l, r;
            scanf ("%d%d", &l, &r);
            printf ("%d\n", TREE.query_sum(l, r));
        }
        else if (opt == 4)
        {
            int l, r;
            scanf ("%d%d", &l, &r);
            printf ("%d\n", TREE.query_(segtree::max_value()).max_value());
        }
        else
        {
            int l, r;
            scanf ("%d%d", &l, &r);
            orignal.using = true;
            basic_ostringstream Stream = TREE.orignal(-1);
            ostringstream orignal = TREE.c_orignal(Stream, 0);
            orignal.color(segtree::segment(l, r), true, nullptr);
            printf ("%d\n", orignal.query_sum(l, r));
            orignal.vcolor(segtree::segment(l, r), true, nullptr);
            free(orignal);
            orignal.using = false;
        }
    }
    free(nullptr);
    TREE.clear();
    return 0;
}
