class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r,l,sum;
        r= 0;
        l= numbers.size()-1;
        while(r < l){
            sum = numbers[r] + numbers[l];
            if(sum < target){
                r += 1;
            }
            else if(sum > target){
                l -=1;
            }
            else{
                return {r + 1 , l + 1};
            }
        }
        return {};
    }
};
