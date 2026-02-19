#include <bits/stdc++.h>
using namespace std;

vector<int> findMissing(vector<int>& arr, int low, int high) {
    unordered_set<int> s;
    for (int x : arr){
        s.insert(x);
    }
    vector<int> ans;

    for (int i = low; i <= high; i++) {
        if (s.find(i) == s.end()){
            ans.push_back(i);
        }   
    }

    return ans;
}

int main() {

    vector<int> arr = {2, 5, 7, 10};

    int low = 1, high = 10;

    vector<int> result = findMissing(arr, low, high);

    for (int x : result)
        cout << x << " ";

    return 0;
}
