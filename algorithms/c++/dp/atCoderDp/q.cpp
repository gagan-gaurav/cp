#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	ll n; cin >> n;
	vector<ll> h(n);
	vector<ll> a(n);
	vector<ll> dp(n + 1);

	ll internal_nodes = 1;
	while( internal_nodes <= n){
		internal_nodes *= 2;
	}
	vector<ll> tree(2 * internal_nodes);

	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int flower = 0; flower < n; flower++){
		// dp[h[flower]] = (max of  dp in range 0 to h[flower] - 1 ) + a[flower];
		
		ll l = 1, r = internal_nodes + h[flower];
		ll ans = 0;

		while(l < r){
			if(r & 1) ans = max(ans, tree[r - 1]);
			r /= 2;
		}

		dp[h[flower]] =  ans + a[flower];

		// update into the tree.

		for(int i = internal_nodes + h[flower]; i >= 1; i /= 2){
			tree[i] = max(tree[i], dp[h[flower]]);
		}


		// for(int j = 0; j < h[flower]; j++){  // above the same thing is implemented using segment tree
		// 	dp[h[flower]] = max(dp[h[flower]], dp[j] + a[flower]); 
		// }
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}