#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int i = 0, sign = 1;
    int n = s.size();

    while(i < n && s[i] == ' ') {
        i++;
    }

    if (i == s.size()) return 0;

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    long long ans = 0;
    while(i < n && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');

        if(ans > INT_MAX) {
            if(sign == 1) {
                cout << INT_MAX << '\n';
                return 0;
            }
            else {
                cout << INT_MIN << '\n';
                return 0;
            }
        }
        i++;
    }
    ans = ans * sign;
    cout << ans << '\n';
    return 0;
}
