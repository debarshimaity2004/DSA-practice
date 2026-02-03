#include <bits/stdc++.h>
using namespace std;

int countSmallerEqual(vector<vector<int>> &mat, int n, int m, int x)
{

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        // count elements <= x in this row
        cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
    }

    return cnt;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int low = INT_MAX;
    int high = INT_MIN;

    // find min and max
    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m) / 2 + 1; // position of median

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        int cnt = countSmallerEqual(mat, n, m, mid);

        if (cnt >= req)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << "\n";

    return 0;
}
