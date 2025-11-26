
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i = 0, j = n - 1;
        while (i != j) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
};
