#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long s = 0, s2 = 0;

    for(int i = 0; i < n; i++) {
        s += a[i];
        s2 += a[i] * a[i];
    }

    long long sn = (long long)n * (n + 1) / 2;
    long long s2n = (long long)n * (n + 1) * (2*n + 1) / 6;

    long long val1 = s - sn;              // x - y
    long long val2 = s2 - s2n;        // x^2 - y^2

    long long sumRM = val2 / val1;            // x + y

    long long x = (val1 + sumRM) / 2;
    long long y = sumRM - x;

    cout << "Repeating: " << x << '\n';
    cout << "Missing: " << y << '\n';

    return 0;
}
