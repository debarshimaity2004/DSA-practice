#include<bits/stdc++.h>
using namespace std;

long long countPairs(vector<int>& a, int low, int mid, int high) {
    long long cnt = 0;
    int j = mid + 1;

    for(int i = low; i <= mid; i++) {
        while(j <= high && (long long)a[i] > 2LL * a[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }

    return cnt;
}

void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if(a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        }
        else {
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

long long mergeSort(vector<int>& a, int low, int high) {
    long long cnt = 0;

    if(low < high) {
        int mid = (low + high) / 2;

        cnt += mergeSort(a, low, mid);
        cnt += mergeSort(a, mid + 1, high);
        cnt += countPairs(a, low, mid, high);
        merge(a, low, mid, high);
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
