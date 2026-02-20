#include <bits/stdc++.h>
using namespace std;

static bool comparator(string a, string b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& arr) {

    vector<string> nums;
    for (int x : arr)
        nums.push_back(to_string(x));

    sort(nums.begin(), nums.end(), comparator);

    if (nums[0] == "0")
        return "0";

    string result = "";
    for (string s : nums)
        result += s;

    return result;
}

int main() {

    vector<int> arr = {3, 30, 34, 5, 9};

    cout << largestNumber(arr);

    return 0;
}