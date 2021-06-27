#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
    }

vector<int> get_div(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            d.push_back(n / i);
        }
    }
    getunique(d);
    return d;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n = 100;
    vector<int> dp(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> d = get_div(i);
        for (auto j : d) {
            if (j != 1 && j != i)
                dp[i] |= !dp[i - j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << (dp[i] ? ": Alice" : ": Bob") << '\n';
    }
    return 0;
}