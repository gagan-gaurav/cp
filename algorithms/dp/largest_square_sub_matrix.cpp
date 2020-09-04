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

int dp(int (&m)[8][6]){
  int a[8][6];
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 6; j++){
      a[i][j] = m[i][j];
    }
  }
  int max = 0;
  // print(a);
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 6; j++){
      if(i && j && m[i][j]){
        a[i][j] = 1  + min({a[i-1][j-1],a[i-1][j],a[i][j-1]});
        if(a[i][j] > max) max = a[i][j];
      }
    }
  }
  print(a);
  // cout << a[0][0];
  return max;
}

int main(){
  int mat[8][6] =
  	{
  		{ 0, 0, 1, 0, 1, 1 },
  		{ 0, 1, 1, 1, 0, 0 },
  		{ 0, 0, 1, 1, 1, 1 },
  		{ 1, 1, 0, 1, 1, 1 },
  		{ 1, 1, 1, 1, 1, 1 },
  		{ 1, 1, 0, 1, 1, 1 },
  		{ 1, 0, 1, 1, 1, 1 },
  		{ 1, 1, 1, 0, 1, 1 }
  	};
    int ans = dp(mat);

    cout << ans  <<'\n';
  return 0;
}
