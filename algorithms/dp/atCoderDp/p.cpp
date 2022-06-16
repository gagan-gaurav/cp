#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mod = 1e9 + 7;
vector<vector<int>> adj;
vector<bool> visited;

int mul(int a, int b){
	return (ll) a * b % mod;
}

// pair.first -> no. of ways the node can be white, pair.second -> no. of ways the node can be black. 
pair<int, int> dfs(int u){
	visited[u] = true;
	int all_child_node_is_white = 1;
	int some_child_node_is_black = 0;
	for(auto &i: adj[u]){
		if(!visited[i]){
			pair<int, int> p = dfs(i);
			some_child_node_is_black = (mul(some_child_node_is_black, (p.first + p.second)) + mul(all_child_node_is_white, p.second)) % mod;
			all_child_node_is_white = mul(all_child_node_is_white, p.first);
		}
	}
	return make_pair((all_child_node_is_white + some_child_node_is_black) % mod, all_child_node_is_white);
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	adj.assign(n + 1, vector<int> ());
	visited.assign(n + 1, false);
	for(int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pair<int, int> ans = dfs(1);
	cout << (ans.first + ans.second) % mod << '\n';
	return 0;
}