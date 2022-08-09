#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";  // adding dummy characters for edge cases.
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));   // fixing the value of p[i] if i is inbetween the l and r (which is inside the current palindrome.).
        while(s[i - p[i]] == s[i + p[i]]) {      // increasing value of p[i] if characters on the both side of s[i] is same (which means it is a palindrome.).
            p[i]++;
        }
        if(i + p[i] > r) {  // assigning the new value of l and r.
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
	// cout << t;
    vector<int> res = manacher_odd(t + "#"); //// #a#b#a#b#a#b#a#
    return vector<int>(begin(res) + 1, end(res) - 1);  // a#b#a#b#a#b#a
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	string s = "abababa"; 
	vector<int> d2 = manacher(s);
    for(int i = 0;  i < d2.size(); i++){
        int x = d2[i] / 2;
        if(i%2 == 0) d2[i] = 2 * x - 1;  // full length of odd palindrome substring.
        else d2[i] -= 1; // full length of even palindrome substring.
    }
	for(auto i: d2) cout << i << ' ';
	return 0;
}