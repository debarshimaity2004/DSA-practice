#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums,int n) {
    int breaks =0;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            breaks++;
        }
    }
    if(nums[n-1] >nums[0]){
        breaks++;
    }
    return breaks <=1;       
}

int main(){
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    if(check(array,n)){
        cout<<"true\n";
    }
    else cout<<"false\n";

    return 0;
    
}