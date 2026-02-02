//assuming the rows are sorted wrna 2 for loop lagake krdo

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int ans = -1;
    int mx = 0;

    for(int i = 0; i < n; i++){

        int idx = lower_bound(a[i].begin(), a[i].end(), 1) - a[i].begin();

        int cnt = m - idx;

        if(cnt > mx){
            mx = cnt;
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
