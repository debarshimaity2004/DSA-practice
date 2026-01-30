#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>& nums, int mid, int threshold){
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
        sum += (nums[i] + mid - 1) / mid;  // ceil

        if(sum > threshold) return false;
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int threshold;
    cin >> threshold;

    int low = 1;
    int high = INT_MIN;

    for(int i = 0; i < n; i++){
        high = max(high, nums[i]);
    }

    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(checker(nums, mid, threshold)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
