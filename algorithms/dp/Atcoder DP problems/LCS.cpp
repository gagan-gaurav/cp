#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp((int)s.size() + 1,
                           vector<int>((int)t.size() + 1, 0));
    for (int i = 1; i <= (int)s.size(); i++) {
        for (int j = 1; j <= (int)t.size(); j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    int i = (int)s.size();
    int j = (int)t.size();
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}