#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	string a, b; cin >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int> (b.size() + 1, 0));
	for(int i = 1; i <= (int)a.size(); i++){
		for(int j = 1; j <= (int)b.size(); j++){
			if(a[i - 1] ==  b[j - 1]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans = "";
	int i = (int)a.size(), j = (int)b.size();
	while((i != 0 && j != 0)){
		if(a[i -1] == b[j - 1]){
			ans += a[i - 1];
			i--;
			j--;
		}
		else if(dp[i - 1][j] >= dp[i][j - 1]) i--;
		else j--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}