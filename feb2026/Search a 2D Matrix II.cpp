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

    int i = 0;
    int j = m - 1;

    bool found = false;

    while(i < n && j >= 0){

        if(matrix[i][j] == target){
            found = true;
            break;
        }
        else if(matrix[i][j] > target){
            j--;
        }
        else{
            i++;
        }
    }

    if(found) cout << "true\n";
    else cout << "false\n";

    return 0;
}
