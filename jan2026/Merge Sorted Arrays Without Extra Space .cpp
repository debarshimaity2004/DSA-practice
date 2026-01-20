/*for leetcode this code works well and literally don't teach you anything
but if in nums1 the zeroes are not given at the end then we need to use gap method
gap = (gap / 2) + (gap % 2). if need to revise and refer strivers video int he array hard section
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n);
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    vector<int> nums2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }

    for (int x : nums1)
    {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}
