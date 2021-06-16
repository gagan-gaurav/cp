#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int N, MAX_W;
    int MAX_V = 100000;
    cin >> N >> MAX_W;
    vector<int> val(N);
    vector<int> wt(N);
    for (int i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(MAX_V + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= MAX_V; j++) {
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (j >= val[i - 1]) {
                dp[i][j] =
                    min(dp[i - 1][j], dp[i - 1][j - val[i - 1]] + wt[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= MAX_V; i++) {
        if (dp[N][i] <= MAX_W) ans = i;
    }
    cout << ans << '\n';
    return 0;
}