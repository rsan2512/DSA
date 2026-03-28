#include <bits/stdc++.h>
using namespace std;
int minmele(vector<int>& nums){
    int low=0,high=nums.size()-1,minm=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        minm=min(minm,nums[mid]);
        if(nums[mid]>nums[high]) low=mid+1;
        else high=mid-1;
    }return minm;
}
int main(){
    vector<int> ques={5,6,1,2,3,4};
    int minm=minmele(ques);
    cout<<minm;
}