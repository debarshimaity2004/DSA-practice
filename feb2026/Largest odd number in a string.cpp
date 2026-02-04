#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int ind = -1;

    // find last odd digit
    for(int i = s.length() - 1; i >= 0; i--){
        if((s[i] - '0') % 2 == 1){
            ind = i;
            break;
        }
    }

    // if no odd digit found
    if(ind == -1){
        cout << "" << "\n";
        return 0;
    }

    // remove leading zeros
    int i = 0;
    while(i <= ind && s[i] == '0'){
        i++;
    }

    string ans = s.substr(i, ind - i + 1);

    cout << ans << "\n";

    return 0;
}
