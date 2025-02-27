#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[2100000];

void add_self(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int> (n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	
	dp[0] = 1;

	for(int mask = 0; mask < (1 << n); mask++){
		int i = __builtin_popcount(mask); // i -> (i - 1)th indexed man.
		if(i == 0) continue;
		for(int j = 0; j < n; j++){
			if(mask & (1 << j) && a[i - 1][j]){ // can (i - 1)th indexed man be matched with jth indexed women.
				add_self(dp[mask], dp[mask ^ (1 << j)]); //add the previous state in which (i - 1)th man  and jth woman are not mathched.
			}

		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}