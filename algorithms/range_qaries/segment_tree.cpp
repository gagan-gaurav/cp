#include <bits/stdc++.h>
using namespace std;
#define MAXN 5

int t[32];  // 4*n size of memory needed in worst case

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    int n = 8;
    int a[8] = {3, 1, 2, 5, 6, 4, 3, 2};
    build(a, 1, 0, n - 1);
    cout << sum(1, 0, n - 1, 4, 6) << '\n';
    // update(1, 0, n - 1, 1, 10);
    // cout << sum(1, 0, n - 1, 0, 2) << '\n';
    return 0;
}