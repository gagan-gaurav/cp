#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> e;
	dsu(int N) { e.assign(N, - 1);}

	// get representive component (uses path compression)
	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b){
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	// union by size
	bool merge(int x, int y){
		
	}

};

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}