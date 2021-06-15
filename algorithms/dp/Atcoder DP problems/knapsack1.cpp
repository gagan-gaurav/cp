#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int N, MAX_W;
    cin >> N >> MAX_W;
    vector<ll> w(N);
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(MAX_W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_W; j++) {
            if (j >= w[i - 1]) {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            } else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][MAX_W] << '\n';
    return 0;
}