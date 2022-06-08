//recursive solution

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<ll> v;
// ll dp[3005][3005];

// ll solve(int i, int j){
// 	if(i > j) return 0;
// 	if(dp[i][j] != -1) return dp[i][j];
// 	ll ans = 0;
// 	ans += max(v[i] - solve(i + 1, j), v[j] - solve(i, j - 1));
// 	return dp[i][j] = ans;
// }

// int main(){
// 	ios_base ::sync_with_stdio(false);
// 	cin.tie(0);
// 	int n; cin >> n;
// 	v.assign(n + 1, 0);
// 	memset(dp, -1, sizeof(dp));
// 	for(int i = 1; i <= n; i++) cin >> v[i];
// 	cout << solve(1, n);
// 	return 0;
// }


// iterative solution 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> v;
ll dp[3005][3005];

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	v.assign(n + 1, 0);
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = n; i >= 1; i--){
		for(int j = i; j <= n; j++){
			if(i == j) dp[i][j] = v[i];
			else dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1]);
		}
	}

	cout << dp[1][n] << '\n';
	return 0;
}