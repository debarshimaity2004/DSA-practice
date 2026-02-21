#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {

    int n = citations.size();

    vector<int> count(n + 1, 0);

    for (int c : citations) {

        if (c >= n)
            count[n]++;
        else
            count[c]++;
    }

    int papers = 0;

    for (int i = n; i >= 0; i--) {

        papers += count[i];

        if (papers >= i)
            return i;
    }

    return 0;
}

int main() {

    vector<int> citations = {3, 0, 5, 3, 0};

    cout << hIndex(citations);

    return 0;
}