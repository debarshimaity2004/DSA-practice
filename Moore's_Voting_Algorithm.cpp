#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int candidate = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            candidate = a[i];
            count = 1;
        }
        else if(a[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    cout << candidate << '\n'; //when its gauranted of majority element present, else loop chalake check krlo
    return 0;
}
