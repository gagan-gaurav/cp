#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define modulo 1e9 + 7  // double value

template <typename T>  // vector
void print(vector<T> &v) {
    for (auto &i : v) cout << i << ' ';
    cout << '\n';
}

template <typename T>  // 2d vector
void print(vector<vector<T>> &v) {
    for (auto i : v) {
        for (auto j : i) cout << j << ' ';
        cout << '\n';
    }
}

template <typename T, size_t N>  // vector array
void print(vector<T> (&a)[N]) {
    for (int i = 0; i < N; i++) {
        for (auto &j : a[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

template <typename T, typename U>  // vector pair
void print(vector<pair<T, U>> &a) {
    for (auto &i : a) {
        cout << i.first << " " << i.second << '\n';
    }
}

template <typename T, size_t N>  // vector pair array
void print(vector<pair<T, T>> (&a)[N]) {
    for (int i = 0; i < N; i++) {
        for (auto &j : a[i]) {
            cout << "(" << j.first << "," << j.second << ") ";
        }
        cout << '\n';
    }
}

template <typename T, typename U>  //2d vector pair
void print(vector<vector<pair<T, U>>> &v) {
    for (auto &i : v) {
        for (auto &j : i) {
            cout << '(' << j.first << " " << j.second << ')' << ',';
        }
        cout << '\n';
    }
}

template <typename T, size_t N, size_t M>  // 2d array
void print(T (&theArray)[N][M]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cout << theArray[x][y] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

template <typename T, size_t N>  // 1d array
void print(T (&theArray)[N]) {
    for (int x = 0; x < N; x++) {
        cout << theArray[x] << " ";
    }
    cout << "\n";
}

template <typename T, typename U>
void print(unordered_map<T, U> umap) {
    for (auto &i : umap) {
        cout << "(" << i.first << "," << i.second << ") ";
    }
    cout << "\n";
}

template <typename T>
void print(unordered_set<T> uset) {
    for (auto &i : uset) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T, size_t N>  // vector tuple array
void print(vector<tuple<T, T, T>> (&a)[N]) {
    for (int i = 0; i < N; i++) {
        for (auto &j : a[i]) {
            cout << "{" << get<0>(j) << "," << get<1>(j) << "," << get<2>(j) << "}, ";
        }
        cout << '\n';
    }
}

int main() {
    return 0;
}
