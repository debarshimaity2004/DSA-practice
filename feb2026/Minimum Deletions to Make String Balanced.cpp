#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int b_count = 0;  
    int ans = 0;      

    for(char c : s){
        if(c == 'b'){
            b_count++;
        }
        else{ 
            ans = min(ans + 1, b_count);
        }
    }
    cout << ans << '\n';
    return 0;
}
