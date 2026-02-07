#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long s = 0;   // sum 
    long long r = 0;   // initial value

    for(int i = 0; i < n; i++){
        s += arr[i];
        r += (long long)i * arr[i];
    }

    long long ans = r;
    for(int k = 1; k < n; k++){
        r = r + s - (long long)n * arr[n - k];
        ans = max(ans, r);
    }
    cout << ans << '\n';
    return 0;
}
