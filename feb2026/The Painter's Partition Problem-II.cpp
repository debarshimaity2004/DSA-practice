#include <bits/stdc++.h>
using namespace std;

bool canPaint(vector<int> &arr, int k, long long maxTime)
{

    long long curr = 0;
    int painters = 1;

    for (int len : arr)
    {

        if (curr + len <= maxTime)
        {
            curr += len;
        }
        else
        {
            painters++;
            curr = len;

            if (painters > k)
                return false;
        }
    }

    return true;
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);

    long long ans = high;

    while (low <= high)
    {

        long long mid = (low + high) / 2;

        if (canPaint(arr, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
