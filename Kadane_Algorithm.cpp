#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long sum = 0;
    long long maxi = LLONG_MIN;

    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }

    cout << maxi << '\n';
    return 0;
}
