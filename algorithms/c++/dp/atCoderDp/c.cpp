#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> dp(n, vector<int> (3, 0));
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for(int i = 1; i < n; i++){
		int a, b, c; cin >> a >> b >> c;
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + c;
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
	return 0;
}