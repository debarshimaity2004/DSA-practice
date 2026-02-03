#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    int low = 0;
    int high = n * m - 1;

    bool found = false;

    while(low <= high){

        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if(matrix[row][col] == target){
            found = true;
            break;
        }
        else if(matrix[row][col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(found) cout << "true\n";
    else cout << "false\n";

    return 0;
}
