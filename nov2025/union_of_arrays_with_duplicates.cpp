// tc...o(n+m)
// sc...o(n+m)

// class Solution {
//   public:
//     vector<int> findUnion(vector<int>& a, vector<int>& b) {
//         // code here
//         unordered_set<int> s;

//         for (int x : a) s.insert(x);
//         for (int x : b) s.insert(x);

//         vector<int> res(s.begin(), s.end());
//         return res;
//     }
// };

//method-2:space optimized
// tc:O(nlogn +mlogm)
// sc:O(1)

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                if (res.empty() || res.back() != a[i])
                    res.push_back(a[i]);
                i++; 
                j++;
            }
            else if (a[i] < b[j]) {
                if (res.empty() || res.back() != a[i])
                    res.push_back(a[i]);
                i++;
            }
            else {
                if (res.empty() || res.back() != b[j])
                    res.push_back(b[j]);
                j++;
            }
        }

        while (i < a.size()) {
            if (res.empty() || res.back() != a[i])
                res.push_back(a[i]);
            i++;
        }

        while (j < b.size()) {
            if (res.empty() || res.back() != b[j])
                res.push_back(b[j]);
            j++;
        }

        return res;
    }
};

