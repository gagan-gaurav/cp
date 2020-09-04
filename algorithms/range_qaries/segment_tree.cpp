#include <bits/stdc++.h>
using namespace std;
#define MAXN 5

int t[10];


template< typename T, size_t N > // 1d array
void print( T(&theArray)[N]  ) {
    for ( int x = 0; x < N; x ++ ) {
    cout << theArray[x] << " ";
    }
    cout<<"\n";
}

void build(int a[], int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int  sum(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr)/2;
    return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val){
    
}

int main(){
    int n = 5;
    int a[5] = {1, 3 ,-2, 8, -7};
    build(a, 1, 0, n-1);
    print(t);
    return 0;
}