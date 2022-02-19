/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<vector<ll>>> dp;
ll l, r, k, d; 
string s;

ll pro(ll n, ll sum, ll f){ // k -> sum -> count of digits == d, f = 0 or 1, n = position.
	if(sum > k) return 0;

	if(n == s.size()){
		if(k == sum) return 1;
		return 0;
	}

	if(dp[n][sum][f] != -1) return dp[n][sum][f];
	
	ll ans = 0;

	ll limit;
	if(f == 0) limit = s[n] - '0';
	else limit = 9;

	for(int i = 0; i <= limit; i++){
		ll nf = f;
		ll nsum = sum;
		if(f == 0 && i < limit) nf = 1;
		if(i == d) nsum++;
		if(nsum <= k) ans += pro(n + 1, nsum, nf);
	}
	
	return dp[n][sum][f] = ans;
}

ll solve(ll r){
	s = to_string(r);
	dp.assign(20, vector<vector<ll>> (180, vector<ll> (2, -1)));
	ll ans = pro(0, 0, 0);
	return ans;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	cin >> l >> r >>  d >> k;
	cout << solve(r) << ' ' << solve(l - 1);
	return 0;
}