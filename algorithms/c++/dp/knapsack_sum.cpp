#include <bits/stdc++.h>
using namespace std;

/* you are given  N <= 1000, each with some  weight w[i],
Is there a subset with total weight exactly W? W <= 10^6 */

const int MAX_W = 1000000;

// void solve_using_2d_matrix(int n, vector<int> &a, vector<vector<bool>> &dp) {
//     dp.assign(n + 1, vector<bool>(MAX_W + 1, false));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j < MAX_W; j++) {
//             if (j == 0) {
//                 dp[i][j] = true;
//             } else if (j < a[i - 1]) {
//                 dp[i][j] = dp[i - 1][j];
//             } else {
//                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
//             }
//         }
//     }
// }

bitset<MAX_W + 1> dp;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    dp[0] = true;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp |= (dp << a[i]);

        // replaced this loop by above line
        // for (int j = w; j >= x; j--) {
        //     if (dp[j - x]) dp[j] = true;
        // }
    }
    cout << (dp[w] ? "yes" : "no");
    return 0;
}