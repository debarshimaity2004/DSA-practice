#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>& a, int n, int k, double mid){

    int cnt = 0;

    for(int i = 1; i < n; i++){

        double gap = a[i] - a[i-1];

        int needed = (int)(gap / mid);

        if(gap / mid == needed) needed--;

        cnt += needed;

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

    double low = 0;
    double high = 0;

    for(int i = 1; i < n; i++){
        high = max(high, (double)(a[i] - a[i-1]));
    }

    double ans = high;

    while(high - low > 1e-6){

        double mid = (low + high) / 2.0;

        if(checker(a, n, k, mid)){
            ans = mid;
            high = mid;
        }
        else{
            low = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << "\n";

    return 0;
}
