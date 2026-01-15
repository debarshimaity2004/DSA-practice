#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    unordered_map<int,int> mp;
    mp[0] = 1;

    int prefix_sum = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        prefix_sum += nums[i];
        int remove = prefix_sum - k;

        cnt += mp[remove];
        mp[prefix_sum]++;
    }

    cout << cnt << '\n';
    return 0;
}
