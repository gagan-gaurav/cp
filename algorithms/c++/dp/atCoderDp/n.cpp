#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll dp[405][405];
 
int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n + 1);
	vector<ll> sum(n + 1, 0);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] += a[i] + sum [i - 1];
	}
	for(int l = n; l >= 1; l--){
		for(int r = l; r <= n; r++){
			if(l == r) dp[l][r] = 0;
			else{
				dp[l][r] = LLONG_MAX;
				for(int i = l; i <= r - 1; i++){
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + sum[r] - sum[l - 1]);
				}
			}
		}
	}
	cout << dp[1][n] << '\n';
	return 0;
}