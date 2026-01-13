#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans(n, 0);
    int positive_index = 0;
    int negative_index = 1;

    for(int i = 0; i < n; i++) {
        if(nums[i] < 0) {
            ans[negative_index] = nums[i];
            negative_index += 2;
        }
        else {
            ans[positive_index] = nums[i];
            positive_index += 2;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}
