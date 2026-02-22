#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXOR(vector<int>& arr, int k) {

    unordered_map<int,int> mp;

    int xr = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        xr = xr ^ arr[i];
        if (xr == k)
            count++;

        if (mp.find(xr ^ k) != mp.end())
            count += mp[xr ^ k];

        mp[xr]++;
    }
    return count;
}

int main() {

    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << countSubarraysWithXOR(arr, k);

    return 0;
}