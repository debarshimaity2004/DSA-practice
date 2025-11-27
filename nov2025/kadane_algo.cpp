// tc:O(n)
// sc:O(1)
// maximum subarray sum

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        long long sum=0,maxi=LONG_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
