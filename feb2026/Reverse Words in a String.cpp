#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    getline(cin, s);   // take full line input

    string result = "";
    int i = s.size() - 1;

    while(i >= 0){

        // skip spaces
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        if(i < 0) break;

        int end = i;

        // find start of word
        while(i >= 0 && s[i] != ' '){
            i--;
        }

        string word = s.substr(i + 1, end - i);

        if(!result.empty()){
            result += " ";
        }

        result += word;
    }

    cout << result << "\n";

    return 0;
}
