#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    int left = 0, right = 0;
    int sum = 0;
    int maxLen = 0;

    while(right < n) {
        sum += nums[right];

        while(left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    cout << maxLen << '\n';
    return 0;   
}