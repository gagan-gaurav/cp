//  problem url :->   https://vjudge.net/problem/LightOJ-1068

#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<vector<vector<int>>>> dp;
int a, b ,k;

// pos -> postion of digit, sum -> sum of digits, f = 0 -> digit should be < b[pos], f = 1 -> any digit, num -> modulo of number formed.
int count(int pos, int sum, int f, int num) {
	if(pos == v.size()){
		if(sum % k == 0 && num == 0) return 1;
		return 0;
	}

	if(dp[pos][sum][num][f] != -1) return dp[pos][sum][num][f];

	int ans = 0, limit;
	if(f == 0) limit = v[pos];
	else limit = 9;

	for(int i = 0; i <= limit; i++){
		int nf = f;
		if(nf == 0 && i < limit) nf = 1;
		ans += count(pos + 1, sum + i, nf, (num * 10 + i) % k);
	}

	return dp[pos][sum][num][f] = ans;
} 


int solve(int aa){
	v.clear();
	while(aa){
		v.push_back(aa%10);
		aa /= 10;
	}
	reverse(v.begin(), v.end());

	dp.assign(10, vector<vector<vector<int>>> (90, vector<vector<int>> (90, vector<int> (2, -1))));

	int ans = count(0, 0, 0, 0);
	return ans;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int T, t = 1; cin >> T;
	while(t <= T){
		cin >> a >> b >> k;
		if(k > 90) cout << "Case " << t++ << ": " << 0 << '\n';      // sum of digits cannot be greater than 90. if k > 90, 90 is not divisible by k.
		else cout << "Case " << t++ << ": " << solve(b) - solve(a - 1) << '\n';
	}
	return 0;
}
