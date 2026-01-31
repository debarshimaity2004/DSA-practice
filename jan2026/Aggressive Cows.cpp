#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& a, int n, int k, int dist){

    int cnt = 1;        // first cow placed
    int last = a[0];

    for(int i = 1; i < n; i++){

        if(a[i] - last >= dist){
            cnt++;
            last = a[i];
        }

        if(cnt >= k) return true;
    }

    return false;
}

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int low = 1;
    int high = a[n-1] - a[0];
    int ans = 0;

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(canPlace(a, n, k, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
