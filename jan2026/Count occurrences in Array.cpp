#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    auto it1 = lower_bound(a.begin(), a.end(), x);
    auto it2 = upper_bound(a.begin(), a.end(), x);

    int count = it2 - it1;

    cout << count << '\n';

    return 0;
}
