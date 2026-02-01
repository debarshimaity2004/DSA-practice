#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for(int i = 1; i < n; i++){

        if(nums[i] < min1){
            min2 = min1;
            min1 = nums[i];
        }
        else if(nums[i] < min2){
            min2 = nums[i];
        }
    }

    int ans = nums[0] + min1 + min2;

    cout << ans << "\n";

    return 0;
}
