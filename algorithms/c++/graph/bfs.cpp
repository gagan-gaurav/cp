#include <bits/stdc++.h>
using namespace std;

// bfs algorithm //

vector<vector<int>> adj;
queue<int> q;

void bfs(int n, int s, vector<int> &d, vector<int> &p) {
    vector<bool> visited(n + 1, false);
    d.assign(n + 1, 0);
    p.assign(n + 1, -1);
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &i : adj[v]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                d[i] = d[v] + 1;
                p[i] = v;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) adj.push_back(vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> d, p;
    bfs(n, 1, d, p);
    for (auto &i : d) cout << i << ' ';
    return 0;
}
