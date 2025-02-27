#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

void sub(int &a, int b){
	a -= b;
	if(a < 0) a += mod;
}


int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k; 
	vector<int> dp(k + 1);  // dp[i] ->  no. of ways i candies are used.

	dp[0] = 1;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		vector<int> sum(k + 1);
		for(int used = k; used >= 0; used--){
			int t = dp[used];
			int l = used + 1;
			int r = used + min(a, k - used);
			if(l <= r){
				add(sum[l], t);
				if(r + 1 <= k) sub(sum[r + 1], t);
			}
		}
		int pre = 0;
		for(int i = 0; i <= k; i++){
			add(pre, sum[i]);
			add(dp[i], pre);
		}
	}

	cout << dp[k] << '\n';

	return 0;
}