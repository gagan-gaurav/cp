#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<bool> root(n + 1, true);
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		root[y] = false;
	}
	vector<int> len(n + 1, 1);
	vector<bool> visited(n + 1, false);
 
	function<void(int&)> dfs = [&](int &u){
		if(visited[u]) return;
		visited[u] = true;
		for(auto i: v[u]){
			dfs(i);
			len[u] = max(len[u], len[i] + 1);
		}
	};
 
	for(int i = 1; i <= n; i++){
		if(root[i]) dfs(i);
	}
 
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, len[i]);
	}
	cout << ans - 1 << '\n';
 
	return 0;
}