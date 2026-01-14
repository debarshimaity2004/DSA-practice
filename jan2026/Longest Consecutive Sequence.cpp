#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    unordered_set<int> st;
    for(int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    int longest = 1;

    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;

            while(st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }

    cout << longest << '\n';
    return 0;
}
