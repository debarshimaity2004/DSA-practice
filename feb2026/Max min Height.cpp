#include <bits/stdc++.h>
using namespace std;

bool canAchieve(vector<long long> &arr, int n, long long k, int w, long long target)
{

    vector<long long> added(n, 0);

    long long operations = 0;
    long long currAdd = 0;

    for (int i = 0; i < n; i++)
    {

        currAdd += added[i];

        long long height = arr[i] + currAdd;

        if (height < target)
        {

            long long need = target - height;

            operations += need;

            if (operations > k)
                return false;

            currAdd += need;

            if (i + w < n)
                added[i + w] -= need;
        }
    }

    return true;
}

int main()
{

    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long k;
    cin >> k;

    int w;
    cin >> w;

    long long low = *min_element(arr.begin(), arr.end());
    long long high = low + k;

    long long ans = low;

    while (low <= high)
    {

        long long mid = (low + high) / 2;

        if (canAchieve(arr, n, k, w, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
