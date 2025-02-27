#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m;
vector<vector<ll>> dp;

void solve(int i, int j, int mask, int next_mask){
	if(i == n) return;
	if(j >= m) dp[i + 1][next_mask] += dp[i][mask];
	else{
		int current_cell = (1 << j);
		if(current_cell & mask){
			solve(i, j + 1, mask, next_mask);                                                        // if current cell is occupied.
		}else{
			solve(i, j + 1, mask, next_mask | current_cell);										 // if current cell is empty.
			if(j + 2 <= m &&  !(mask & current_cell) && !(mask & (current_cell << 1))){		
				solve(i, j + 2, mask, next_mask);                                                    //if current and next cells are empty.
			}
		}
	}
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dp.assign(n + 1, vector<ll> (1 << m));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int mask = 0; mask < (1 << m); mask++){
			solve(i, 0, mask, 0);
		}
	}
	cout << dp[n][0] <<'\n';
	return 0;
}