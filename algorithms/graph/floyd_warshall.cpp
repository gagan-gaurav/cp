#include <bits/stdc++.h>
using namespace std;

vector<vector<unsigned int>> d;
const unsigned int INF = UINT_MAX / 2;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    d.assign(n + 1, vector<unsigned int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        d[x][y] = w;
        d[y][x] = w;
    }
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return 0;
}