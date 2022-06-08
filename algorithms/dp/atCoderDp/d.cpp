#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n, w; cin >> n >> w;
	vector<ll> v(n + 1), u(n + 1);
	for(int i = 1; i <= n; i++) cin >> u[i] >> v[i];
	vector<vector<ll>> dp(n + 1, vector<ll> (w + 1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= w; j++){
			if(u[i] <= j) dp[i][j] = max(dp[i - 1][j - u[i]] + v[i], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][w] << '\n';
	return 0;
}