#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n; 

    vector<long long> arr(n-1);

    for(int i = 0; i < n-1; i++){
        cin >> arr[i];
    }

    long long total = (long long)n * (n + 1) / 2;
    long long sum = 0;

    for(int x : arr){
        sum += x;
    }

    cout << (total - sum) << '\n';

    return 0;
}
