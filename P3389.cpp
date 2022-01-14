#include <bits/stdc++.h>
using namespace std;

const double eps = 1E-8;

int n;
double x[100010];
double a[1010][1010];

// const char *MSG_ERR = "No Solution";

void gauss() {
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            if (fabs(a[j][i]) > 1E-8) {
                for (int k = 1; k <= n + 1; k ++)
                    swap (a[i][k], a[j][k]);
            }
        }
        if (fabs(a[i][i]) < 1E-8) {
            puts("No Solution");
            exit(0);
        }
        for (int j = i + 1; j <= n; j ++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 1; k <= n + 1; k ++)
                a[j][k] -= a[i][k] * ratio;
        }
    }
    for (int i = n; i >= 1; i --) {
        for (int j = i + 1; j <= n; j ++)
            a[i][n + 1] -= a[i][j] * x[j];
        x[i] = a[i][n + 1] / a[i][i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n + 1; j ++)
            scanf ("%lf", &a[i][j]);
    gauss();
    for (int i = 1; i <= n; i ++)
        printf("%.2lf\n", x[i]);
    return 0;
}
