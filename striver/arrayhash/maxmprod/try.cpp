#include <bits/stdc++.h>
using namespace std;
int maxsub(vector<int>& arr){
    int n=arr.size();
    int suffix=1,prefix=1;
    int maxm=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            suffix=1;
            maxm=max(maxm,0);
        }
        else{suffix*=arr[i];
            maxm=max(suffix,maxm);
    }}int maxp=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==0){
            prefix=1;
            maxm=max(maxm,0);
        }
        else{prefix*=arr[i];
        maxp=max(prefix,maxp);
    }}
    return max(maxm,maxp);
}
int main(){
    vector<int> arr={-2,0,-1};
    int  maxm=maxsub(arr);
    cout<<maxm;
}