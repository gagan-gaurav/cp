#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dp;
int ans = 0;

void dfs(int s) {
    visited[s] = true;
    for (auto &i : adj[s]) {
        if (!visited[i]) dfs(i);
        dp[s] = max(dp[s], dp[i] + 1);
        ans = max(ans, dp[s]);
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    dp.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    cout << ans << '\n';
    return 0;
}