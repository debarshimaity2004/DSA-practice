#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i=0;
    int n=nums.size();
    for(int j=0;j<n;j++){            
        if(nums[i] != nums[j]){               
            nums[i+1]=nums[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int uniqueElements= removeDuplicates(nums);
    cout<<uniqueElements<<'\n';
}