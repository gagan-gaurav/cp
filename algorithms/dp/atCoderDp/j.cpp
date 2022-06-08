#include <bits/stdc++.h>
using namespace std;

int n;
double dp[301][301][301];

double solve(int a, int b, int c){
	if(a < 0 || b < 0 || c < 0) return 0;
	if(a == 0 && b == 0 && c == 0) return 0;
	if(dp[a][b][c] > -0.5) return dp[a][b][c];
	double ans = 0;
	double base = a + b + c;
	ans += n + a * solve(a - 1, b, c) + b * solve(a + 1, b - 1, c) + c * solve(a, b + 1, c - 1);
	return dp[a][b][c] = ans/base;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<int> a(3, 0);
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x - 1]++;
	}
	memset(dp, -1, sizeof(dp));
	cout << setprecision(10) << fixed << solve(a[0], a[1], a[2]) << '\n';
	return 0;
}