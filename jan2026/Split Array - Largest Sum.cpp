#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>& a, int n, int k, int mid){

    int cnt = 1;   // number of subarrays
    long long sum = 0;

    for(int i = 0; i < n; i++){

        if(a[i] > mid) return false;

        if(sum + a[i] <= mid){
            sum += a[i];
        }
        else{
            cnt++;
            sum = a[i];
        }

        if(cnt > k) return false;
    }

    return true;
}

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    int ans = high;

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(checker(a, n, k, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
