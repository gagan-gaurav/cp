#include <bits/stdc++.h>
using namespace std;

#define fast { ios_base::sync_with_stdio(false); }
#define io { cin.tie(NULL);cout.tie(NULL);}
#define all(v) v.begin(), v.end()
#define getunique(v){sort(all(v));v.erase(unique(all(v)), v.end());}

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A &v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, size_t N> 
string to_string(A (&a)[N]){
    bool first = true;
    string res = "{";
    for (const auto& x : a) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << to_string(H) << (sizeof...(Tail) ? " | ": "");
    debug_out(T...);
}

template <typename Head,size_t N, typename... Tail, size_t... M>
void debug_out(Head(&H)[N], Tail(&... T)[M]) {
    cerr << to_string(H) << (sizeof...(Tail) ? " | ": "");
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


int main(){
	fast io
#ifdef LOCAL
auto begin = std::chrono::high_resolution_clock::now();
#endif

    vector<int> v = {2, 3, 4, 5, 6, 7};
    vector<int> p[3] = {{1, 2}, {2}, {2, 3, 4}};
    int a[2][2][3] = {{{1, 4, 2}, {4, 5, 3}}, {{12, 45, 3}, {2, 3, 2}}};
    pair<int, int> k = {6, 7};
    set<int> u = {2, 3, 4};
    vector<int> l = {2, 3};

	// vectors  can be debugged with other containers
    debug(v, u, k);

	// arrays in any form should be debugged only with other arrays or alone
    debug(p);
    debug(a);

#ifdef LOCAL
auto end = std::chrono::high_resolution_clock::now();
cout << endl <<setprecision(4) << fixed;
cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
    return 0;
}