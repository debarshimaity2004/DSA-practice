#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;
    int ans = a.size();

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;
    int ans = a.size();

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    // Manual implementation
    int lb = lowerBound(a, x);
    int ub = upperBound(a, x);

    cout << "Lower Bound: " << lb << '\n';
    cout << "Upper Bound: " << ub << '\n';

    /*
    ================= STL VERSION =================

    int lb = *lower_bound(a.begin(), a.end(), x) ;
    int ub = *upper_bound(a.begin(), a.end(), x) ;

    cout << "Lower Bound: " << lb << endl;
    cout << "Upper Bound: " << ub << endl;

    ===============================================
    */

    return 0;
}
