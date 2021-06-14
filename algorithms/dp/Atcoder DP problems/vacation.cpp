#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
    return 0;
}