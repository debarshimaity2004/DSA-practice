#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;

    sort(a.begin(), a.end());

    int ans = INT_MAX;

    for(int i = 0; i + m - 1 < n; i++){

        int diff = a[i + m - 1] - a[i];

        ans = min(ans, diff);
    }

    cout << ans << '\n';

    return 0;
}
