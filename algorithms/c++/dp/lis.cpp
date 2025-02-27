#include <bits/stdc++.h>
using namespace std;

//time complexity is nlogn.

int lis(vector<int> &a) {
    int n = (int)a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();  // or use binary search to find j
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF) ans = i;
    }
    return ans;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v = {0};
    cout << lis(v) << '\n';
    return 0;
}