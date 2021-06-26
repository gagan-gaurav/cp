#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) v.begin(), v.end()
#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
    }

namespace number_theory {
ll gcd(ll x, ll y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return gcd(y, x % y);
}

bool isprime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

bool prime[15000105];
void sieve(int n) {
    for (ll i = 0; i <= n; i++) prime[i] = 1;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = prime[0] = 0;
}

vector<ll> primelist;
bool __primes_generated__ = 0;

void genprimes(int n) {
    __primes_generated__ = 1;
    sieve(n + 1);
    for (ll i = 2; i <= n; i++)
        if (prime[i]) primelist.push_back(i);
}

vector<ll> prime_factors(ll n) {
    if (!__primes_generated__) {
        cerr << "Call genprimes function first" << endl;
        exit(1);
    }
    vector<ll> facs;

    for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
        if (n % primelist[i] == 0) {
            while (n % primelist[i] == 0) {
                n /= primelist[i];
                facs.push_back(primelist[i]);
            }
        }
    }
    if (n > 1) {
        facs.push_back(n);
    }
    sort(facs.begin(), facs.end());
    return facs;
}

vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }

    getunique(divs);
    return divs;
}
}  // namespace number_theory

using namespace number_theory;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}