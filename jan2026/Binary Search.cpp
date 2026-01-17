#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target;
    cin >> target;

    int low = 0, high = n - 1;
    int flag = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] == target) {
            cout << mid << '\n'; 
            flag = 1;
            break;
        }
        else if(a[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(flag == 0) {
        cout << -1 << '\n';
    }

    return 0;
}
