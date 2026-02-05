#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int l = 0;
    int zeros = 0;
    int maxLen = 0;

    for(int r = 0; r < n; r++) {

        if(arr[r] == 0) {
            zeros++;
        }

        while(zeros > k) {

            if(arr[l] == 0) {
                zeros--;
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    cout << maxLen << '\n';

    return 0;
}
