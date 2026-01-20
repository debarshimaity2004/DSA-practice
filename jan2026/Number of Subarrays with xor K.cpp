#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    unordered_map<int,int> mp;
    mp[0] = 1;

    int prefixXor = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        prefixXor ^= a[i];

        int need = prefixXor ^ k;

        if(mp.find(need) != mp.end()) {
            count += mp[need];
        }

        mp[prefixXor]++;
    }

    cout << count << '\n';
    return 0;
}
