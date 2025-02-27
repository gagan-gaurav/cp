#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n = 100;
vector<bool> is_prime(n + 1, true);
vector<ll> primes;

void chk_prime() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; (ll)i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

vector<ll> div(ll n) {
    vector<ll> prime_fact;
    for (ll d : primes) {
        while (n % d == 0) {
            prime_fact.push_back(d);
            n /= d;
        }
    }
    if (n > 1) prime_fact.push_back(n);
    return prime_fact;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    chk_prime();
    vector<long long> ans = div(24);
    for (auto &i : ans) cout << i << " ";
    return 0;
}