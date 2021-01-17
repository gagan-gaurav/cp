#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bipartite_check(int n) {
    bool is_bipartite = true;
    queue<int> q;
    vector<int> color(n + 1, -1);
    for (int t = 1; t <= n; t++) {
        if (color[t] == -1) {
            q.push(t);
            color[t] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto &i : adj[v]) {
                    if (color[i] == -1) {
                        color[i] = color[v] ^ 1;
                        q.push(i);
                    } else {
                        is_bipartite &= color[i] != color[v];
                    }
                }
            }
        }
    }
    is_bipartite ? cout << "YES" << '\n' : cout << "NO" << '\n';
    for (auto &i : color) cout << i << " ";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) adj.push_back(vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bipartite_check(n);
    return 0;
}