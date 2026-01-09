#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxi = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == 1) {
            count++;
            maxi = max(maxi, count);
        }
        else {
            count = 0;
        }
    }

    cout << maxi << '\n';
    return 0;
}
