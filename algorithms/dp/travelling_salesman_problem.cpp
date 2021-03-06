#include <bits/stdc++.h>
using namespace std;

int n = 4;
int dp[16][4];

int d[4][4] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

//if all cities are visited
int visitedAll = (1 << n) - 1;

int tsp(int mask, int pos) {
    if (mask == visitedAll) {
        return d[pos][0];
    }

    //Lookup
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // try visit an  usvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = d[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) dp[i][j] = -1;
    }
    cout << tsp(1, 0);
    return 0;
}