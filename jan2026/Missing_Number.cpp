#include<bits/stdc++.h>
using namespace std;

//solution using formula
// int main() {
//     int n;
//     cin >> n;

//     int a[n];
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     int total = n * (n + 1) / 2;
//     int sum = 0;

//     for(int i = 0; i < n; i++) {
//         sum += a[i];
//     }

//     cout << total - sum << '\n';
//     return 0;
// }

//solution using XOR
int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ i;
    }
    xor1 = xor1 ^ n;
    int result=xor1 ^ xor2;
    cout<<result ;
    return 0;
}
