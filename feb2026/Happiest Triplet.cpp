#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n), b(m), c(l);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < l; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int i = 0, j = 0, k = 0;

    int bestDiff = INT_MAX;
    int bestSum = INT_MAX;

    int x = 0, y = 0, z = 0;

    while(i < n && j < m && k < l){

        int A = a[i];
        int B = b[j];
        int C = c[k];

        int maxi = max({A, B, C});
        int mini = min({A, B, C});

        int diff = maxi - mini;
        int sum = A + B + C;

        if(diff < bestDiff || (diff == bestDiff && sum < bestSum)){
            bestDiff = diff;
            bestSum = sum;

            x = A;
            y = B;
            z = C;
        }

        // move pointer of minimum
        if(mini == A) i++;
        else if(mini == B) j++;
        else k++;
    }

    vector<int> ans = {x, y, z};

    // decreasing order
    sort(ans.begin(), ans.end(), greater<int>());

    for(int i = 0; i < 3; i++){
        cout << ans[i] << " ";
    }

    cout << '\n';

    return 0;
}
