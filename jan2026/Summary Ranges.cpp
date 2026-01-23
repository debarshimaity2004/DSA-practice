#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<string> ans;

    for(int i = 0; i < n; i++) {
        long long start = nums[i];

        while(i + 1 < n && nums[i + 1] == nums[i] + 1) {
            i++;
        }

        long long end = nums[i];

        if(start == end) {
            ans.push_back(to_string(start));
        }
        else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }
    }

    for(auto s : ans) {
        cout << s << " ";
    }

    return 0;
}
