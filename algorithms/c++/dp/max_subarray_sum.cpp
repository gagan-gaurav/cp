#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t N>  // 1d array
void print(T (&theArray)[N]) {
    for (int x = 0; x < N; x++) {
        cout << theArray[x] << " ";
    }
    cout << "\n";
}

int dp(int (&a)[6]) {
    int t[6];
    int max = t[0] = a[0];
    for (int i = 1; i < 6; i++) {
        if (a[i] + t[i - 1] < t[i - 1])
            t[i] = 0;
        else {
            t[i] = a[i] + t[i - 1];
        }
        if (t[i] > max) max = t[i];
    }
    print(t);
    return max;
}

int main() {
    int a[6] = {-8, -3, -6, -2, -5, -4};
    int ans = dp(a);
    cout << ans;
    return 0;
}
