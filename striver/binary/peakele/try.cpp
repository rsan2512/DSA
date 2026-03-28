#include <bits/stdc++.h>
using namespace std;
int peakele(vector<int>& nums){
    int n= nums.size();
    int low=0,high=n-1;
    while(low<high){
        int mid=(high+low)/2;
        if(nums[mid]>nums[mid+1]) high=mid;
        else low=mid+1;
    }return low;
}
main(){
    vector<int> ques={1,2,3,4,5,3,1};
    int ind=peakele(ques);
    cout<<ques[ind];
}