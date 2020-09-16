#include <bits/stdc++.h>
using namespace std;

struct edges{
    int a, b, cost; 
};
int n, m, v;
vector<edges> e;
const int INF = 1000000000;

vector<int> solve(){
    vector<int> d(n+1, INF);
    d[v] = 0;
    for(;;){
        bool any = false;
        for(int j = 0; j < m; j++){
            if(d[e[j].a] < INF)
                if(d[e[j].b] > d[e[j].a] +e[j].cost){
                    d[e[j].b] = d[e[j].a] +e[j].cost;
                    any = true;
                }
                
        }
        if(!any) break;
    }
    return d;
}

int main(){
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        edges x;
        cin >> x.a >> x.b >> x.cost;
        e.push_back(x);
    }
    vector<int> ans = solve();
    for(int  & i : ans) cout << i << " ";
    return 0;
}