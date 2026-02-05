#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int p = 0;
    int ans = 0;

    for(char x : s){
        if(x == '('){
            p++;
        }
        else if(x == ')'){
            p--;
        }

        ans = max(ans, p);
    }

    cout << ans << '\n';

    return 0;
}
