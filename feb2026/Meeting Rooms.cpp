#include <bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& arr) {

    // Step 1: sort by start time
    sort(arr.begin(), arr.end());

    // Step 2: check overlap
    for (int i = 1; i < arr.size(); i++) {

        if (arr[i][0] < arr[i-1][1]) {
            return false;
        }
    }

    return true;
}

int main() {

    vector<vector<int>> arr = {{1,4}, {10,15}, {7,10}};

    if (canAttendMeetings(arr))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
