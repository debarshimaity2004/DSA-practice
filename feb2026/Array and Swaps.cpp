// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        maxFreq = max(maxFreq, freq[x]);
    }

    if (maxFreq <= (n + 1) / 2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}