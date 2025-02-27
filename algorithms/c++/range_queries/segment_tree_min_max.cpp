#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

// int n = 10000;
pair<int, int> t[16];

pair<int, int> combine(string s, pair<int, int> a, pair<int, int> b) {
    if (s == "max") {
        if (a.first > b.first)
            return a;
        if (b.first > a.first)
            return b;
    } else if (s == "min") {
        if (a.first < b.first)
            return a;
        if (b.first < a.first)
            return b;
    }
    return make_pair(a.first, a.second + b.second);
}

void build(string s, int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(s, a, v * 2, tl, tm);
        build(s, a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(s, t[v * 2], t[v * 2 + 1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine("max", get_max(v * 2, tl, tm, l, min(r, tm)), get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine("min", get_min(v * 2, tl, tm, l, min(r, tm)), get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(string s, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(s, v * 2, tl, tm, pos, new_val);
        else
            update(s, v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(s, t[v * 2], t[v * 2 + 1]);
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int v[n];
    for (auto i : v) cout << i << ' ';
    // int a[8] = {7, 1, 2, 6, 6, 6, 3, 2};
    // build("min", a, 1, 0, n - 1);
    // pair<int, int> s = get_min(1, 0, n - 1, 2, 7);
    // cout << s.first << " " << s.second;
    return 0;
}