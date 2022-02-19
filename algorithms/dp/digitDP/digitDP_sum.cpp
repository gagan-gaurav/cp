/// find number of integers between l and r having sum of their digits = k.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<vector<ll>>> dp;
ll l, r, k; 
string s;

ll pro(ll n, ll sum, ll f){ // k -> sum -> count of digits == d, f = 0 or 1, n = position.
	if(sum < 0) return 0;

	if(n == s.size()){
		if(sum == 0) return 1;
		return 0;
	}

	if(dp[n][sum][f] != -1) return dp[n][sum][f];
	
	ll ans = 0;

	ll limit;
	if(f == 0) limit = s[n] - '0';
	else limit = 9;

	for(int i = 0; i <= limit; i++){
		ll nf = f;
		if(f == 0 && i < limit) nf = 1;
		if(sum - i >= 0) ans += pro(n + 1, sum - i, nf);
	}
	
	return dp[n][sum][f] = ans;
}

ll solve(ll r){
	s = to_string(r);
	dp.assign(20, vector<vector<ll>> (180, vector<ll> (2, -1)));
	ll ans = pro(0, k, 0);
	return ans;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	cin >> l >> r >> k;
	cout << solve(r) << ' ' << solve(l - 1);
	return 0;
}