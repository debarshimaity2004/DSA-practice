#include<bits/stdc++.h>
using namespace std;

int main() {
    string haystack, needle;
    cin >> haystack >> needle;

    int n = haystack.size();
    int m = needle.size();

    for(int i = 0; i <= n - m; i++) {
        int j = 0;
        while(j < m && haystack[i + j] == needle[j]) {
            j++;
        }
        if(j == m) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
