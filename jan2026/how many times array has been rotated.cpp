#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        // If search space is already sorted
        if (arr[low] <= arr[high])
        {

            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            break;
        }

        // Left part sorted
        if (arr[low] <= arr[mid])
        {

            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }

            low = mid + 1;
        }

        // Right part sorted
        else
        {

            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }

            high = mid - 1;
        }
    }

    return index;
}