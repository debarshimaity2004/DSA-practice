#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix = prefix * arr[i];
        suffix = suffix * arr[n - i - 1];
        ans = max(ans, max(prefix, suffix));
    }
    cout << ans << '\n';
    return 0;
}
