#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s = "1";

    for(int step = 2; step <= n; step++){
        string next = "";
        int cnt = 1;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                next += to_string(cnt);
                next += s[i-1];
                cnt = 1;
            }
        }
        next += to_string(cnt);
        next += s.back();
        s = next;
    }
    cout << s << '\n';
    return 0;
}
