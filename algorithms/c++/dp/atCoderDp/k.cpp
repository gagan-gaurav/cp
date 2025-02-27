#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<bool> dp(k + 1, false);  // dp[i] is TRUE if first player can win with i stones remaining. 
	for(int i = 0; i <= k; i++){
		for(auto j : a){
			if(i >= j && !dp[i - j]) dp[i] = true;
		}
	}
	cout << (dp[k] ? "First" : "Second") << '\n';
	return 0;
}