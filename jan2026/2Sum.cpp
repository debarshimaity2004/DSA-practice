#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int left=0;
    int right=n-1;
    while(left < right){
        if(a[left]+a[right] == target){
            cout<<"YES";
            return 0;
        }
        else if(a[left]+a[right] < target){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<"NO";
    return 0;
}