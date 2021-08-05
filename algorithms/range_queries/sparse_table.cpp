#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 100005; // equal to max length of array.
const int K = 17;
ll st[MAXN][K + 1];
vector<int> a;


//range sum query
 
void rsq(){                    // O(N*logN)
	for(int i = 0; i < a.size(); i++) st[i][0] = a[i];
	for(int j = 1; j <= K; j++){
		for(int i = 0; i + (1 << j) <= a.size(); i++)
			st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1]; //  st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 2])
	}
}

ll sum_query(int L, int R){          // O(logN)
	ll sum = 0;
	for(int j = K; j >= 0; j--){
		if((1 << j) <= R - L + 1){
			sum += st[L][j];
			L += 1 << j;
		}
	}
	return sum;
}


/// rang minimum query implementation

vector<int> lg(MAXN + 1);  //log value preprocessing

void rmq(){                       // O(N*logN)
	lg[1] = 0;
	for(int i = 2; i <= MAXN; i++) lg[i] = lg[i / 2] + 1;

	for(int i = 0; i < a.size(); i++) st[i][0] = a[i];
	for(int j = 1; j <= K; j++){
		for(int i = 0; i + (1 << j) <= a.size(); i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);  //  st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 2])
	}
}

int min_query(int L, int R){       // O(1)
	int j = lg[R - L + 1];
	int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
	return minimum;
}


int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	int n = 10;
	a.assign(n, 0);
	a = {1, 3 , 4, 5, 2 ,5 ,6 ,7, 4, 10};
	rmq();
	cout << min_query(0, 9);
	return 0;
}