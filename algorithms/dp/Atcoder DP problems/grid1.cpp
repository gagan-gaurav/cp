#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    dp[1][0] = dp[1][1] = dp[0][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && g[i - 1][j - 1] == '.')
                dp[i][j] = dp[i][j - 1];
            else if (j == 1 && g[i - 1][j - 1] == '.')
                dp[i][j] = dp[i - 1][j];
            else {
                if (g[i - 1][j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << dp[h][w] << '\n';
    return 0;
}