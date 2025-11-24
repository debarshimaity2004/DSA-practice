//Note: Don't return any array, just in-place on the array.
// tc:O(n)
// sc:O(n)

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int> temp;
        int n;
        n=arr.size();
        // temp.reserve(n);used for speed
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) temp.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) temp.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};
