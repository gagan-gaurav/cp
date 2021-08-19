#include <bits/stdc++.h>
using namespace std;

// time complexity O((n + q)* sqrt(n))

void remove(int index); //implement
void add(int index);	//implement
int get_answer();		//implement

int BLOCK_SIZE;        //sqrt(N)

struct Query{
	int l, r, index;
	bool operator <(Query other) const{
		return make_pair(l/BLOCK_SIZE, r) < make_pair(other.l/BLOCK_SIZE, other.r);
	}
};

vector<int> ma(vector<Query> queries){
	vector<int> answers(queries.size());
	sort(queries.begin(), queries.end());

	int current_left = 0;
	int current_right = -1;

	for(Query q : queries){
		while(current_left > q.l){
			current_left--;
			add(current_left);
		}
		while(current_right < q.r){
			current_right++;
			add(current_right);
		}
		while(current_left < q.l){
			remove(current_left);
			current_left++;
		}
		while(current_right > q.l){
			remove(current_right);
			current_right--;
		}
		answers[q.index] = get_answer();
	}
	return answers;
}



int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}