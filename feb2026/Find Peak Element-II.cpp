#include<bits/stdc++.h>
using namespace std;

int findMaxElement(vector<vector<int>>& mat, int n, int col){

    int maxValue = -1;
    int index = -1;

    for(int i = 0; i < n; i++){

        if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            index = i;
        }
    }

    return index;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int low = 0;
    int high = m - 1;

    int row = -1, col = -1;

    while(low <= high){

        int mid = (low + high) / 2;

        int maxRow = findMaxElement(mat, n, mid);

        int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

        if(mat[maxRow][mid] > left && mat[maxRow][mid] > right){

            row = maxRow;
            col = mid;
            break;
        }
        else if(mat[maxRow][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << row << " " << col << "\n";

    return 0;
}
