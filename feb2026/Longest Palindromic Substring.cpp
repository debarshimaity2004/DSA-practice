#include <bits/stdc++.h>
using namespace std;

int expandFromCenter(string &s, int left, int right){

    while(left >= 0 && right < s.size() && s[left] == s[right]){
        left--;
        right++;
    }

    return right - left - 1;
}

int main(){

    string s;
    cin >> s;

    int start = 0;
    int end = 0;

    for(int i = 0; i < s.size(); i++){

        int len1 = expandFromCenter(s, i, i);       // odd length
        int len2 = expandFromCenter(s, i, i + 1);   // even length

        int maxLen = max(len1, len2);

        if(maxLen > end - start){

            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    cout << s.substr(start, end - start + 1) << '\n';

    return 0;
}
