#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long x) {
    long long sum = 0;

    while (x) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main() {

    long long n, d;
    cin >> n >> d;

    long long left = 1, right = n;
    long long pos = -1;

    while (left <= right) {

        long long mid = (left + right) / 2;

        if (mid - digitSum(mid) >= d) {
            pos = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (pos == -1)
        cout << 0 << endl;
    else
        cout << (n - pos + 1) << endl;

    return 0;
}
