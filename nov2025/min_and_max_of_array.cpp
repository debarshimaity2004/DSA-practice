//tc:O(n)
//sc:O(1)
//this question proves that don't get happy after the solution seems obvious.uska follow up question me fun chupa rehta hai xD
class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mini, maxi, i;
        // Initialize min and max
        if (n % 2 == 1) {
            mini = maxi = arr[0];
            i = 1;
        } else {
            if (arr[0] < arr[1]) {
                mini = arr[0];
                maxi = arr[1];
            } else {
                mini = arr[1];
                maxi = arr[0];
            }
            i = 2;
        }
    
        // Process elements in pairs
        while (i < n - 1) {
            if (arr[i] < arr[i + 1]) {
                mini = min(mini, arr[i]);
                maxi = max(maxi, arr[i + 1]);
            } else {
                mini = min(mini, arr[i + 1]);
                maxi = max(maxi, arr[i]);
            }
            i += 2;
        }
    
        return {mini, maxi};
    }
};
