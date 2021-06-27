#include "bits/stdc++.h"
using namespace std;

#define sim template <class c
#define ris return *this
#define dor > debug& operator<<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c > char dud(...);

struct debug {
#ifdef LOCAL
    ~debug() { cerr << endl; }

template <class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {cerr << boolalpha << i;
        return *this;
} template <class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i));
}


template <class c, class b > debug& operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
}

template <class c > debug& operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
}
#else
    template <class c > debug& operator<<(const c&) { return *this; }
#endif
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

int main() {
    set<int> s = {3, 2, 32, 89, 99, 4};
    vector<pair<int, int>> v = {{1, 2}};
    int a[] = {1, 2, 3};
    debug() << v;
    return 0;
}