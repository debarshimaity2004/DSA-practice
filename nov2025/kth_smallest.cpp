// max-heap method
// tc-O(nlogk)
// sc-O(k)

// class Solution {
//   public:
//     int kthSmallest(vector<int>& arr, int k) {
//         priority_queue<int> maxHeap;
    
//         for (int x : arr) {
//             maxHeap.push(x);
//             if (maxHeap.size() > k)
//                 maxHeap.pop();
//         }
//         return maxHeap.top();
//     }
// };

//quickselect algorithm (optimal on average case O(n))
class Solution {
  public:
    int partition(vector<int>& arr, int l, int r) {
        int pivot = arr[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (arr[j] <= pivot)
                swap(arr[i++], arr[j]);
        }
        swap(arr[i], arr[r]);
        return i;
    }
    
    int quickSelect(vector<int>& arr, int l, int r, int k) {
        if (l == r) return arr[l];
        
        int pos = partition(arr, l, r);
        int count = pos - l + 1;
    
        if (count == k) return arr[pos];
        else if (k < count) return quickSelect(arr, l, pos - 1, k);
        else return quickSelect(arr, pos + 1, r, k - count);
    }
    
    int kthSmallest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, k);
    }
};
