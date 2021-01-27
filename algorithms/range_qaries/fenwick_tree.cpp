#include <bits/stdc++.h>
using namespace std;

// ### To get parent
//
// *  2,s complement
// *  AND with the original  number
// *  substract from the original number

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }
    int sum(int idx) {
        int ret = 0;
        for (idx++; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v = {1, 3, 4, 45, 5, 6, 7, 87, 10};
    FenwickTree f(v);
    cout << f.sum(3, 4);
    return 0;
}