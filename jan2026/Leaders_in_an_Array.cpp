#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxi = a[n - 1];
    cout << maxi << " ";

    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= maxi) {
            maxi = a[i];
            cout << maxi << " ";
        }
    }

    cout << '\n';
    return 0;
}
