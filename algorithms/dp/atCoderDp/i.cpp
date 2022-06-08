//recursive solution..

// #include <bits/stdc++.h>
// using namespace std;


// int n;
// vector<double> p;
// vector<vector<double>> dp;

// double solve(int pos, int count){
// 	if(pos == n) {
// 		if(count > n/2) return 1;
// 		else return 0; 
// 	}
// 	if(dp[pos][count] != -1) return dp[pos][count];

// 	double ans = solve(pos + 1, count) * (1 - p[pos]) + solve(pos + 1, count + 1) * (p[pos]);
// 	return dp[pos][count] = ans;
// }

// int main(){
// 	ios_base ::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> n;
// 	for(int i = 0; i < n; i++){
// 		double d; cin >> d;
// 		p.push_back(d);
// 	}
// 	dp.assign(n, vector<double> (n, -1));
// 	cout << setprecision(10) <<solve(0, 0) << '\n';
// 	return 0;
// }


//iterative solution

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<double> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		double p; cin >> p;
		for(int j = i; j >= 0; j--) { // i coins are tossed have j heads.
			dp[j] = (j == 0 ? 0 : dp[j - 1] * p) + dp[j] * (1 - p);
		}
	}
	double ans = 0;
	for(int i = (n/2) + 1; i <= n; i++) ans += dp[i];
	cout << setprecision(10) << ans << '\n';
	return 0;
}

