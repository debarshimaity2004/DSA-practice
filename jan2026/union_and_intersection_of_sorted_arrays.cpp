#include<bits/stdc++.h>
using namespace std;

vector<int> getUnion(vector<int>& a, vector<int>& b) {
    vector<int> uni;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while(i < n && j < m) {
        if(a[i] == b[j]) {
            if(uni.empty() || uni.back() != a[i])
                uni.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] < b[j]) {
            if(uni.empty() || uni.back() != a[i])
                uni.push_back(a[i]);
            i++;
        }
        else {
            if(uni.empty() || uni.back() != b[j])
                uni.push_back(b[j]);
            j++;
        }
    }

    while(i < n) {
        if(uni.empty() || uni.back() != a[i])
            uni.push_back(a[i]);
        i++;
    }

    while(j < m) {
        if(uni.empty() || uni.back() != b[j])
            uni.push_back(b[j]);
        j++;
    }

    return uni;
}

vector<int> getIntersection(vector<int>& a, vector<int>& b) {
    vector<int> inter;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
        else{
            
            inter.push_back(a[i]);
            i++;
            j++;
        }
    }

    return inter;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> uni = getUnion(a, b);
    vector<int> inter = getIntersection(a, b);

    for(int x : uni) cout << x << " ";
    cout << '\n';

    for(int x : inter) cout << x << " ";
    cout << '\n';

    return 0;
}


