#include <bits/stdc++.h>
using namespace std;

template< typename T, size_t N > // 1d array
void print( T(&theArray)[N]  ) {
    for ( int x = 0; x < N; x ++ ) {
    cout << theArray[x] << " ";
    }
    cout<<"\n";
}

int main(){
    int a[13] = {2, 3, 50, 4, 5, 20, 6, 61, 23, 45, 34, 22, 1};
    int b[13] = {0};
    stack<int> s;
    s.push(-1);
    for(int i = 0; i < 13; i++){
        if(!s.empty()){
            while(a[i] < s.top()){
                s.pop();
            }
        }
        b[i] = s.top();
        s.push(a[i]);
    }
    print(b);
    return 0;  
}