#include<bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& nums, int k) {
    int n=nums.size();
    k = k%n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    rotateArray(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}