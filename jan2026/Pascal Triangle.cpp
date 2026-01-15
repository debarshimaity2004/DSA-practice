#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long val = 1;
    vector<int> ans;

    ans.push_back(1);

    for(int col = 1; col < row; col++) {
        val = val * (row - col);
        val = val / col;
        ans.push_back(val);
    }

    return ans;
}

int main() {
    int numRows;
    cin >> numRows;

    vector<vector<int>> triangle;

    for(int i = 1; i <= numRows; i++) {
        triangle.push_back(generateRow(i));
    }

    for(int i = 0; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
