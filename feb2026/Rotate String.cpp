#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, goal;
    cin >> s >> goal;

    if(s.length() != goal.length()){
        cout << "false\n";
        return 0;
    }

    string doubledS = s + s;

    if(doubledS.find(goal) != string::npos){
        cout << "true\n";
    }
    else{
        cout << "false\n";
    }

    return 0;
}
