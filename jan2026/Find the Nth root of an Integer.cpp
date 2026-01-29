#include<bits/stdc++.h>
using namespace std;

long long power(long long a, int n, long long limit){
    long long res = 1;

    for(int i = 0; i < n; i++){
        res = res * a;

        if(res > limit) return limit + 1; // overflow / too big
    }

    return res;
}

int main(){
    long long m;
    int n;

    cin >> n >> m;   // n = root, m = number

    long long low = 1, high = m;
    long long ans = -1;

    while(low <= high){
        long long mid = (low + high) / 2;

        long long val = power(mid, n, m);

        if(val == m){
            ans = mid;
            break;
        }
        else if(val < m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
