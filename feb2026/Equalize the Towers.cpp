#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> heights(n);
    vector<int> cost(n);

    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }

    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++){
        v.push_back({heights[i], cost[i]});
    }

    sort(v.begin(), v.end());

    long long totalCost = 0;
    for(int i = 0; i < n; i++){
        totalCost += v[i].second;
    }

    long long prefix = 0;
    int targetHeight = 0;

    for(int i = 0; i < n; i++){
        prefix += v[i].second;
        if(prefix >= (totalCost + 1) / 2){
            targetHeight = v[i].first;
            break;
        }
    }

    long long ans = 0;

    for(int i = 0; i < n; i++){
        ans += 1LL * abs(v[i].first - targetHeight) * v[i].second;
    }

    cout << ans << '\n';

    return 0;
}
