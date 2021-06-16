#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int N, MAX_W;
    int MAX_V = 100000;
    cin >> N >> MAX_W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];
    vector<vector<int>> dp(N + 1, vector<int>(MAX_V + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_V; j++) {
        }
    }
    return 0;
}