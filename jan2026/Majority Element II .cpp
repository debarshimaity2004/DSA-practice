#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && nums[i] != ele2) {
            ele1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && nums[i] != ele1) {
            ele2 = nums[i];
            cnt2 = 1;
        }
        else if(nums[i] == ele1) cnt1++;
        else if(nums[i] == ele2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == ele1) cnt1++;
        else if(nums[i] == ele2) cnt2++;
    }

    int mini = n / 3 + 1;

    if(cnt1 >= mini) cout << ele1 << " ";
    if(cnt2 >= mini) cout << ele2 << " ";

    cout << '\n';
    return 0;
}
