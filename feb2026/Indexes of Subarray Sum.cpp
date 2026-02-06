#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    long long target;
    cin >> target;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    long long sum = 0;

    for(int right = 0; right < n; right++){
        sum += arr[right];

        while(sum > target && left <= right){
            sum -= arr[left];
            left++;
        }

        if(sum == target){
            cout << left + 1 << " " << right + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
