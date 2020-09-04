#include <bits/stdc++.h>
using namespace std;

template< typename T, size_t N, size_t M > // 2d array
void print( T(&theArray)[N][M]  ) {
    for ( int x = 0; x < N; x ++ ) {
        for ( int y = 0; y < M; y++ ) {
            cout << theArray[x][y] << " ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int knapsack(int (&wt)[6], int (&val)[6], int n, int w){
  int a[7][11];
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= w; j++){
      if(i == 0 || j == 0) a[i][j] = 0;
      else if(wt[i-1] <= j){
        a[i][j] = max(val[i-1] + a[i-1][j - wt[i-1]], a[i-1][j]);
      }
      else{a[i][j] = a[i-1][j];}
    }
  }
  print(a);
  return a[6][10];
}

int main(){
  int w = 10, n = 6;
  int wt[6] = { 1, 2,  3,  8,  7, 4 };
  int val[6] = { 20, 5, 10, 40, 15, 25 };
  int ans = knapsack(wt, val, n, w);
  cout << ans << '\n';
  return 0;
}
