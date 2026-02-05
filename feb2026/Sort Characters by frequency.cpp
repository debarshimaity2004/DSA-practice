#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char,int> mp;

    // Count frequency
    for(char c : s){
        mp[c]++;
    }

    vector<pair<int,char>> v;

    // Store (frequency, character)
    for(auto x : mp){
        v.push_back({x.second, x.first});
    }

    // Sort in decreasing order
    sort(v.rbegin(), v.rend());

    string ans = "";

    // Build answer
    for(auto p : v){
        ans += string(p.first, p.second);
    }

    cout << ans << '\n';

    return 0;
}
