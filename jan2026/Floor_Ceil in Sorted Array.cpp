#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] <= x) {
            ans = a[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int findCeil(vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] >= x) {
            ans = a[mid];
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

    int floorVal = findFloor(a, x);
    int ceilVal = findCeil(a, x);

    cout << "Floor: " << floorVal << '\n';
    cout << "Ceil: " << ceilVal << '\n';
    return 0;
}
