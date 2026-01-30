#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>& w, int mid, int days){
    int cnt = 1;   // number of days
    int sum = 0;   // current load

    for(int i = 0; i < w.size(); i++){

        if(sum + w[i] <= mid){
            sum += w[i];
        }
        else{
            cnt++;
            sum = w[i];
        }
    }

    return cnt <= days;
}

int main(){
    int n;
    cin >> n;

    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    int days;
    cin >> days;

    int low = INT_MIN;
    int high = 0;

    for(int i = 0; i < n; i++){
        low = max(low, w[i]);  // minimum capacity
        high += w[i];         // maximum capacity
    }

    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(checker(w, mid, days)){
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
