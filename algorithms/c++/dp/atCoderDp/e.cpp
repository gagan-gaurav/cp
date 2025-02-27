#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n, w; cin >> n >> w;
	vector<ll> v(n + 1), u(n + 1);
	for(int i = 1; i <= n; i++) cin >> u[i] >> v[i];
	vector<vector<ll>> dp(n + 1, vector<ll> (100001, INT_MAX));

	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 100001; j++){
			if(j == 0) dp[i][j] = 0;
			else if(j >= v[i]){
				if(dp[i - 1][j - v[i]] != INT_MAX && dp[i - 1][j - v[i]] + u[i] <= w) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + u[i]);
				else if(dp[i - 1][j] != INT_MAX) dp[i][j] = dp[i - 1][j]; 
			}
			else if (dp[i - 1][j] != INT_MAX) dp[i][j] = dp[i - 1][j]; 
		}
	}
	int ans = 0;
	for(int i = 0; i < 100001; i++){
		if(dp[n][i] != INT_MAX)ans = max(ans, i);
	}
	cout << ans << '\n';
	return 0;
}