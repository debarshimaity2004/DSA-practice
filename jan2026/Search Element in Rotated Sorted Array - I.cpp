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

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(nums[mid] == k) {
            ans = mid;
            break;
        }

        // Left part is sorted
        if(nums[low] <= nums[mid]) {

            if(nums[low] <= k && k <= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right part is sorted
        else {

            if(nums[mid] <= k && k <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
