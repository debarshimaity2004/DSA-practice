//TC : O(NLOGN)
//SC : O(1)

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;
    
        sort(arr.begin(), arr.end());
    
        int ans = arr.back() - arr.front();
    
        int smallest = arr[0] + k;
        int largest  = arr.back() - k;
    
        for (int i = 0; i < n - 1; i++) {
            int mn = min(smallest, arr[i + 1] - k);
            int mx = max(largest, arr[i] + k);
    
            if (mn < 0) continue; 
    
            ans = min(ans, mx - mn);
        }
    
        return ans;
    }
};
