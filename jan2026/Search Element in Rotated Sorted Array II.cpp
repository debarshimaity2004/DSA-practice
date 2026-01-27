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

    bool found = false;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(nums[mid] == k) {
            found = true;
            break;
        }

        // If duplicates on both ends
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // Left part sorted
        if(nums[low] <= nums[mid]) {

            if(nums[low] <= k && k <= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right part sorted
        else {

            if(nums[mid] <= k && k <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    if(found)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
