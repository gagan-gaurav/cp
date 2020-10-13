#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int,int>>> adj;
vector<int> d;
priority_queue<pair<int, int>> q;

void dijkstra(int s, vector<int> &d){
    int n = adj.size();
    vector<bool> processed(n, false);
    d.assign(n, INF);
    d[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto &i : adj[a]){
            int b = i.first, w = i.second;
            if(d[a] + w  < d[b]){
                d[b] = d[a] + w;
                q.push({-d[b], b}); 
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n; i++) adj.push_back(vector<pair<int, int>> ());
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    // adj.push_back(vector<pair<int, int>> ());
    // adj[0].push_back({1,2});
    // print(adj);
    dijkstra(1, d);
    for(auto i : d) cout << i <<' ';
    return 0;
}