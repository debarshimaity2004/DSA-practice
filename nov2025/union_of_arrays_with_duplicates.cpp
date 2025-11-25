class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> s;

        for (int x : a) s.insert(x);
        for (int x : b) s.insert(x);

        vector<int> res(s.begin(), s.end());
        return res;
    }
};
