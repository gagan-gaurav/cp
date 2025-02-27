#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> h(n, 0);
	for(int i = 0; i < n; i++) cin >> h[i];
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(i - j >= 0)dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n - 1] << '\n';
	return 0;
}