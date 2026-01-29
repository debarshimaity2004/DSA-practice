#include<bits/stdc++.h>
using namespace std;

bool checker(int mid, vector<int>& piles, int h){
    int hours = 0;

    for(int i = 0; i < piles.size(); i++){
        hours += (piles[i] + mid - 1) / mid;   // ceil without using double

        if(hours > h) return false;
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    vector<int> piles(n);
    for(int i = 0; i < n; i++){
        cin >> piles[i];
    }

    int h;
    cin >> h;

    int low = 1;
    int high = INT_MIN;

    for(int i = 0; i < n; i++){
        high = max(high, piles[i]);
    }

    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(checker(mid, piles, h)){
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
