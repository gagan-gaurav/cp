#include <bits/stdc++.h>
using namespace std;

// There are N persons and N tasks, each task is to be alloted to a single person. We are also given a matrix COST of size N * N ,
//  where COST[i][j]  denotes, how much person 'i' is going to charge for task 'j' .
// Now we need to assign each task to a person in such a way that the total cost is minimum.
//  Note that each task is to be alloted to a single person, and each person will be alloted only one task.

// int count_set_bit(int mask) {
//     if (mask <= 0) return 0;
//     return (mask % 2 == 0 ? 0 : 1) + count_set_bit(mask / 2);
// }
// above function can be replaced by __builtin_popcount(int x) from stl c++ to count number of set bits.

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> dp((int)pow(2, n), INT_MAX);
    dp[0] = 0;
    for (int mask = 0; mask < (int)pow(2, n); mask++) {
        int x = __builtin_popcount(mask);
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[x][j]);
                // if (mask == 1) cout << (mask | (1 << j)) << ":" << dp[mask | (1 << j)] << ' ';
            }
        }
    }

    int ans = dp[pow(2, n) - 1];
    cout << ans << '\n';
    return 0;
}