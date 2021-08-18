#include <bits/stdc++.h>
using namespace std;

// sqrt_decomposition

int n;
vector<int> a;
vector<int> b;
int len;

void build(){
	//preprocessing   O(n)
	len = ceil(sqrt(n));
	b.assign(len, 0);
	for(int i = 0; i < n; i++){
		b[i/len] += a[i];
	}
}

int query(int l, int r){   // O(sqrt(n))
	int sum = 0;
	for(int i = l; i <= r; ){
		if(i % len == 0 && i + len - 1 <= r){
			sum += b[i/len];
			i+=len;
		}else{
			sum += a[i];
			i++;
		}
	}
	return sum;
}

// above solution is slow due to many division operation.

int fast_query(int l, int r){
	int sum = 0;
	int L = l/len, R = r/len;
	if(L == R){
		for(int i = l; i <= r; i++) sum += a[i];
	}
	else{
		for(int i = l, end = (L + 1) * len - 1; i <= end; i++) sum += a[i];
		for(int i = L + 1; i <= R - 1; i++) sum += b[i];
		for(int i = R * len; i <= r; i++) sum += a[i];
	}
	return sum;
}



int main(){
	n = 10;
	a.assign(n, 0);
	// for(int i = 0; i < n; i++) cin >> a[i];
	// build();
	// while(true){
	// 	int l, r; cin >> l >> r;
	// 	cout << query(l, r) <<'\n';
	// }
	return 0;
}