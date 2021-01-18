#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (auto &i : adj[v]) {
        if (color[i] == 0) {
            parent[i] = v;
            if (dfs(i))
                return true;
        } else if (color[i] == 1) {
            cycle_start = i;
            cycle_end = v;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    for (int i = 0; i <= n; i++) {
        if (color[i] == 0 && dfs(i))
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
    }
    find_cycle();
    return 0;
}

// io
// 6 7
// 1 2
// 2 3
// 1 3
// 4 1
// 4 5
// 5 6
// 6 4
// cyclic : 4 5 6 4