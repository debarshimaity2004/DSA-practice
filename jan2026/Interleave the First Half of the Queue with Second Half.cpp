//gfg potd 30th jan 2026

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    queue<int> q;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    vector<int> a(n);

    //even
    int i = 0;
    while(i < n){
        a[i] = q.front();
        q.pop();
        i += 2;
    }

    //odd
    i = 1;
    while(i < n){
        a[i] = q.front();
        q.pop();
        i += 2;
    }

    for(int i = 0; i < n; i++){
        q.push(a[i]);
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << '\n';

    return 0;
}
