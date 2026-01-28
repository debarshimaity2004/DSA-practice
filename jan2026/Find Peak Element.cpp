#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    if(n == 1){
        cout << 0 << '\n';
        return 0;
    }

    if(nums[0] > nums[1]){
        cout << 0 << '\n';
        return 0;
    }

    if(nums[n-1] > nums[n-2]){
        cout << n-1 << '\n';
        return 0;
    }

    int low = 1, high = n - 2;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            cout << mid << '\n';
            return 0;
        }
        else if(nums[mid] > nums[mid-1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << -1 << '\n';
    return 0;
}
