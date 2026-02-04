#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> str(n);
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    if(str.empty()){
        cout << "" << "\n";
        return 0;
    }

    sort(str.begin(), str.end());

    string first = str[0];
    string last = str[n - 1];

    string ans = "";
    int minLength = min(first.size(), last.size());

    for(int i = 0; i < minLength; i++){
        if(first[i] != last[i]) break;
        ans += first[i];
    }

    cout << ans << "\n";
    return 0;
}
