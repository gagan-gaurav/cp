#include <bits/stdc++.h>
using namespace std;

/* Given a graph with n≤2000 vertices and m ≤ n⋅(n−1)/2 edges, count triples of vertices a,b,c 
such that there are edges a−b, a−c and b−c.counting number of triangles in a graph having N nodes.
 N <= 2000 */

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bitset<2001> adj[n + 1];
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
        adj[x] |= (1 << y);
        adj[y] |= (1 << x);
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        int x = v[i].first;
        int y = v[i].second;
        bitset<2001> k = adj[x] & adj[y];
        count += k.count();
    }
    cout << count / 3 << '\n';
    return 0;
}

/*
 test case
6 9
1 2
1 4
2 3
2 4
3 5
3 6
4 5
4 6
5 6
*/