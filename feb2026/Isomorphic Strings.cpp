#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int m1[256] = {0};
    int m2[256] = {0};

    int n = s.size();

    if(s.size() != t.size()){
        cout << "false\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(m1[s[i]] != m2[t[i]]){
            cout << "false\n";
            return 0;
        }

        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }

    cout << "true\n";
    return 0;
}
