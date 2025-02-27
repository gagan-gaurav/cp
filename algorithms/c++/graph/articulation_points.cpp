#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
bool visited[10];
int tin[10], low[10];
int timer = 0;
vector<int> ap;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (auto i : adj[v]) {
        if (i == p) continue;
        if (!visited[i]) {
            dfs(i, v);
            low[v] = min(low[v], low[i]);
            if (low[i] >= tin[v] && p != -1) ap.push_back(v);
            children++;
        } else {
            low[v] = min(low[v], tin[i]);
        }
    }
    if (p == -1 && children > 1) ap.push_back(v);
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << "articulation_points : ";
    for (auto i : ap) cout << i << ',';
    return 0;
}