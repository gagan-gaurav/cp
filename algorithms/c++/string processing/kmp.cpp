#include <bits/stdc++.h>
using namespace std;

// kmp or prefix function.
//time complexity O(n + m).

vector<int> pi_table(string s){            // preprocess the pattern to form pi table.
	int n = s.size();
	vector<int> pi(n);
	for(int i = 1; i < n; i++){
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j]) j = pi[j - 1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int kmp_search(string s1, string s2){      // s1 -> string, s2 -> pattern
	int n = s1.size();
	int m = s2.size();
	vector<int> pi = pi_table(s2);
	int j = 0;
	int index = -1;
	for(int i = 0; i < n; i++){
		while(j > 0 && s1[i] != s2[j]) j = pi[j - 1];
		if(s1[i] == s2[j])j++;
		if(j == m) {
			index = i - j + 1;
		}
 	}
	return index;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);	
	string s1 = "ababcabcabababd";
	string s2 = "ababd";
	cout << kmp_search(s1, s2);
	return 0;
}