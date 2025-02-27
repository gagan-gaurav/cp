#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<double> dp(n + 1, 0);
    dp[0] = 1;                     // dp[heads]
    for (int i = 0; i < n; i++) {  // i = number of coins tossed
        double p;
        cin >> p;
        for (int j = i + 1; j >= 0; j--) {  // j = no. of heads in i tosses
            dp[j] = (j == 0 ? 0 : dp[j - 1] * p) + dp[j] * (1.0 - p);
        }
    }
    double ans = 0;
    for (int i = (n / 2) + 1; i <= n; i++) {
        ans += dp[i];
    }
    cout << setprecision(9) << fixed << ans << '\n';
    return 0;
}