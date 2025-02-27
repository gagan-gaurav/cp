#include <bits/stdc++.h>
using namespace std;

template<typename T> // 2d vector
void print(vector<vector<T>> &v){
  for(auto i : v){
    for(auto j : i) cout << j <<' ';
    cout << '\n';
  }
}

int lcs(string a, string b, size_t x, size_t y){
  vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
  for(int i = 1; i < x+1; i++){
    for(int j = 1; j < y+1; j++){
      if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[x][y];
}

int main(){
  string a, b; cin >> a >> b;
  int ans = lcs(a, b, a.size(), b.size());
  cout << ans <<'\n';
  return 0;
}
