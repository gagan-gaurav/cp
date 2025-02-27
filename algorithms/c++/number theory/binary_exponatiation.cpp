#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}