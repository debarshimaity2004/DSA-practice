#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int l, r;
    cin >> l >> r;

    vector<int> left(l), right(r);

    for(int i = 0; i < l; i++){
        cin >> left[i];
    }

    for(int i = 0; i < r; i++){
        cin >> right[i];
    }

    int ans = 0;

    // For left moving ants
    for(int i = 0; i < l; i++){
        ans = max(ans, left[i]);
    }

    // For right moving ants
    for(int i = 0; i < r; i++){
        ans = max(ans, n - right[i]);
    }

    cout << ans << "\n";

    return 0;
}
