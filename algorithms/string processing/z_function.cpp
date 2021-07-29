#include <bits/stdc++.h>
using namespace std;

vector<int> z;
 
// O(n^2) approch
// void z_func(string s){
//     z.assign((int)s.size(), 0);
//     int n = (int)s.size();
//     for (int i = 1; i < n; i++){
//         while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;
//     }
// }


void z_func(string s){
    int n = (int)s.size();
    z.assign(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        cout << i << ' ' << l << ' ' << r <<' ';
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        cout << z[i] << '\n';
    }
} 

int main(){

    string s = "ababababab";
    z_func(s); 
    for(auto i : z) cout << i << ' ';

    return 0;
}
