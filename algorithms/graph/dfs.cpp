#include <bits/stdc++.h>
using namespace std;

vector<int> adj[N];
bool visited[N];

void dfs(int s){
  if(visited[s]) return;
  visited[s] = true;
  for(int u : adj[s]){
    dfs(u);
  }
}
