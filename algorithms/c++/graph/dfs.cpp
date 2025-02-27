#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (int u : adj[s]) {
        dfs(u);
    }
}
