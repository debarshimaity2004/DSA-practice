#include<bits/stdc++.h>
using namespace std;

long long mergeCount(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    long long cnt = 0;

    while(left <= mid && right <= high) {
        if(a[left] <= a[right]) {
            temp.push_back(a[left++]);
        }
        else {
            temp.push_back(a[right++]);
            cnt += (mid - left + 1);
        }
    }

    while(left <= mid) temp.push_back(a[left++]);
    while(right <= high) temp.push_back(a[right++]);

    for(int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }

    return cnt;
}

long long mergeSort(vector<int>& a, int low, int high) {
    long long cnt = 0;
    if(low < high) {
        int mid = (low + high) / 2;
        cnt += mergeSort(a, low, mid);
        cnt += mergeSort(a, mid + 1, high);
        cnt += mergeCount(a, low, mid, high);
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = mergeSort(a, 0, n - 1);
    cout << ans << '\n';

    return 0;
}
