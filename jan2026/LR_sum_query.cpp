//problem done for algozenith(prefix sum module)

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> prefixSum(n);

    prefixSum[0] = (arr[0] % MOD + MOD) % MOD;
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = (prefixSum[i - 1] + arr[i]) % MOD;
        if (prefixSum[i] < 0) prefixSum[i] += MOD;
    }

    return prefixSum;
}

long long queryRangeSum(const vector<long long>& prefixSum, int L, int R) {
    L--; 
    R--;

    if (L == 0)
        return prefixSum[R];

    long long ans = (prefixSum[R] - prefixSum[L - 1]) % MOD;
    if (ans < 0) ans += MOD;

    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
        cin >> array[i];

    vector<long long> prefixSum = calculatePrefixSum(array);

    while (q--) {
        int L, R;
        cin >> L >> R;

        cout << queryRangeSum(prefixSum, L, R) << '\n';
    }

    return 0;
}
