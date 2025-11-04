//tc : O(n^2)
//sc : O(1)

class Solution {
public:
    vector<int>generateRows(int Rows){
        long long ans=1;
        vector<int>ansRows;
        ansRows.push_back(1);
        for(int col=1;col<Rows;col++){
            ans= ans*(Rows-col);
            ans=ans/(col);
            ansRows.push_back(ans);
        }
        return ansRows;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};