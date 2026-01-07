#include<bits/stdc++.h>
using namespace std;

void rotateArrayByOne(vector<int>& nums) {
    int temp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = temp;
    
}


int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    rotateArrayByOne(nums);
    for(int num:nums){
        cout<<num<<" ";
    }
}