#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 1;

    int ans = INT_MAX;

    while(low <= high) {

        // If already sorted
        if(a[low] <= a[high]) {
            ans = min(ans, a[low]);
            break;
        }

        int mid = (low + high) / 2;

        // Left part sorted
        if(a[low] <= a[mid]) {
            ans = min(ans, a[low]);
            low = mid + 1;
        }

        // Right part sorted
        else {
            ans = min(ans, a[mid]);
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
