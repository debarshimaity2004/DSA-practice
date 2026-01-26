#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    auto it1 = lower_bound(nums.begin(), nums.end(), target);
    auto it2 = upper_bound(nums.begin(), nums.end(), target);

    if(it1 == nums.end() || *it1 != target) {
        cout << -1 << " " << -1 << '\n';
        return 0;
    }

    int first = it1 - nums.begin();
    int last = it2 - nums.begin() - 1;

    cout << first << " " << last << '\n';

    return 0;
}
