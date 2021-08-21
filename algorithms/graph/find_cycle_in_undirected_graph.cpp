#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
    visited[v] = true;
    for (auto &i : adj[v]) {
        if (i == par) continue;
        if (!visited[i]) {
            parent[i] = v;
            if (dfs(i, parent[i]))
                return true;
        } else{
            cycle_start = i;
            cycle_end = v;
            return true;
        }
    }
    return false;
}

void find_cycle() {
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    for (int i = 0; i <= n; i++) {
        if (!visited[i] && dfs(i, parent[i]))
            break;
    }

    if (cycle_start == -1)
        cout << "acyclic" << '\n';
    else {
        vector<int> c;
        c.push_back(cycle_start);
        for (int i = cycle_end; i != cycle_start; i = parent[i]) {
            c.push_back(i);
        }
        c.push_back(cycle_start);
        reverse(c.begin(), c.end());
        cout << "cyclic : ";
        for (auto &i : c) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) adj.push_back(vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_cycle();
    return 0;
}

// io
// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5
// cyclic : 1 3 5 1