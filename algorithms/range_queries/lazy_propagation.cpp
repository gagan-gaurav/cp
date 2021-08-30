#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll MAXN = 2e5 + 5;
ll a [MAXN];

int N, Q;

struct node{
	ll val;
	ll lzAdd;
	ll lzSet;
} tree[MAXN << 2];

#define lc v << 1            // left child
#define rc (v << 1) + 1      // right child

inline void fix_up(int v){
	tree[v].val = tree[lc].val + tree[rc].val;
}

void fix_down(int v, int tl, int tm, int tr){
	if(tree[v].lzSet != 0){  // set same number to all elements in a range.
		tree[lc].lzSet = tree[rc].lzSet = tree[v].lzSet; 
		tree[lc].lzAdd = tree[rc].lzAdd = 0;
		tree[lc].val = (tm - tl + 1) * tree[v].lzSet;
		tree[rc].val = (tr - tm) * tree[v].lzSet; 
		tree[v].lzSet = 0; 
	}else if(tree[v].lzAdd != 0){// add same number to all elements in a range.
		if(tree[lc].lzSet != 0){
			tree[lc].lzSet += tree[v].lzAdd;
			tree[lc].lzAdd = 0; 
		}else{
			tree[lc].lzAdd += tree[v].lzAdd;
		}
		if(tree[rc].lzSet != 0){
			tree[rc].lzSet += tree[v].lzAdd;
			tree[rc].lzAdd = 0; 
		}else{
			tree[rc].lzAdd += tree[v].lzAdd;
		}
		tree[lc].val += (tm - tl + 1) * tree[v].lzAdd;
		tree[rc].val += (tr - tm) * tree[v].lzAdd;
		tree[v].lzAdd = 0;
	}
}

void build(int v, int tl, int tr){
	tree[v].lzAdd = tree[v].lzSet = 0;
	if(tl == tr){
		tree[v].val = a[tl];
	}else{
		int tm = (tl + tr) / 2;
		build(lc, tl, tm);
		build(rc, tm + 1, tr);
		fix_up(v);
	}
}

void add(int v, int tl, int tr, int l, int r, ll val){
	if(r < l) return;
	if(l == tl && r == tr){
		tree[v].val += (r - l + 1) * val;
		if(tree[v].lzSet == 0) tree[v].lzAdd += val;
		else tree[v].lzSet += val;
	}else{
		int tm = (tl + tr) / 2;
		fix_down(v, tl, tm, tr);
		add(lc, tl, tm, l, min(tm, r), val);
		add(rc, tm + 1, tr, max(tm + 1, l), r, val);
		fix_up(v);
	}
}

void set_num(int v, int tl, int tr, int l, int r, ll val){
	if(r < l) return;
	if(l == tl && r == tr){
		tree[v].val = (r - l + 1) * val;
		tree[v].lzSet = val;
		tree[v].lzAdd = 0;
	}else{
		int tm = (tl + tr) / 2;
		fix_down(v, tl, tm, tr);
		set_num(lc, tl, tm, l, min(tm, r), val);
		set_num(rc, tm + 1, tr, max(l, tm + 1), r, val);
		fix_up(v);
	}
}

ll query(int v, int tl, int tr, int l, int r){
	if(r < l) return 0;
	if(tl == l && tr == r) return tree[v].val;
	else{
		int tm = (tl + tr) / 2;
		fix_down(v, tl, tm, tr);
		return query(v * 2, tl, tm, l, min(tm, r)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;             // https://cses.fi/problemset/task/1735/
	for(int i = 1; i <= N; i++) cin >> a[i];
	build(1, 1, N);
	while(Q--){
		int t; cin >> t;
		if(t == 1){
			int l, r, x; cin >> l >> r >> x;
			add(1, 1, N, l, r, x);
		}else if(t == 2){
			int l, r, x; cin >> l >> r >> x;
			set_num(1, 1, N, l, r, x);
		}else if(t == 3){
			int l, r; cin >> l >> r;
			cout << query(1, 1, N, l, r) <<'\n';
		}
	}
	return 0;
}