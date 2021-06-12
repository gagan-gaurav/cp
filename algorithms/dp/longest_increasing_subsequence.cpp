#include <bits/stdc++.h>
using namespace std;

// Time Complexitiy is n^2
// Can be done in O(nlogn) using patience sort

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a = {2, 10, 3, 5, 8, 11};
    vector<int> dp(a.size(), 1);
    int ans = 0;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    cout << ans;
    return 0;
}