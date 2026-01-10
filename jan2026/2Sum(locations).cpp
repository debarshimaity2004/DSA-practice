#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++){
        int need = target - a[i];

        if(mp.find(need) != mp.end()){
            cout << mp[need] << " " << i << '\n';
            return 0;
        }

        mp[a[i]] = i;
    }

    cout << "-1 -1\n";
    return 0;
}
