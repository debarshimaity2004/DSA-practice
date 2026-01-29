#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>& bloomDay, int mid, int m, int k){
    int cnt = 0;      // consecutive flowers
    int bouquet = 0; // total bouquets

    for(int i = 0; i < bloomDay.size(); i++){

        if(bloomDay[i] <= mid){
            cnt++;
        }
        else{
            cnt = 0;
        }

        if(cnt == k){
            bouquet++;
            cnt = 0;
        }
    }

    return bouquet >= m;
}

int main(){
    int n;
    cin >> n;

    vector<int> bloomDay(n);
    for(int i = 0; i < n; i++){
        cin >> bloomDay[i];
    }

    int m, k;
    cin >> m >> k;

    long long need = 1LL * m * k;

    if(need > n){
        cout << -1 << '\n';
        return 0;
    }

    int low = INT_MAX;
    int high = INT_MIN;

    for(int i = 0; i < n; i++){
        low = min(low, bloomDay[i]);
        high = max(high, bloomDay[i]);
    }

    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(checker(bloomDay, mid, m, k)){
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
