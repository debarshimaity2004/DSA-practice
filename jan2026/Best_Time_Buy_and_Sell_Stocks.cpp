#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int mini = prices[0];
    int maxprofit = 0;

    for(int i = 1; i < n; i++) {
        int cost = prices[i] - mini;
        maxprofit = max(maxprofit, cost);
        mini = min(mini, prices[i]);
    }

    cout << maxprofit << '\n';
    return 0;
}
