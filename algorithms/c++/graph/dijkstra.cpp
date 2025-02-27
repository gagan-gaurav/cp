#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> visited(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF) break;

        visited[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                p[to] = v;
                d[to] = d[v] + len;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d;
    vector<int> p;
    // cout << "working";
    // cout << adj.size();
    for (int i = 0; i <= n; i++) {
        adj.push_back(vector<pair<int, int>>());
    }
    // cout << adj.size();

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dijkstra(1, d, p);
    for (auto i : d) cout << i << ' ';
    cout << '\n';
    for (auto i : p) cout << i << ' ';
    return 0;
}