#include<bits/stdc++.h>
using namespace std;

int is_largest(int array[]){
    int maxi=array[0];
    for(int i=0;i<5;i++){
        if(maxi < array[i]){
            maxi=array[i];
        }
    }
    return maxi;
}

int main(){
    int arr[5]={2,3,6,1,4};
    int maximum= is_largest(arr);
    cout<<maximum<<'\n';
}