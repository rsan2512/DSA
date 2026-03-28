#include <bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums,int k){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==k)return true;
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
        if(nums[mid]>=nums[low]){
            if(nums[low]<=k && nums[mid]>k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<k && nums[high]>=k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return false;
}
int main() {
    vector<int> nums = {1,0,1,1,1};
    int target = 0;
    bool result = search(nums, target);

    if(result)
        cout<<"True";
    else 
        cout<<"False";

    return 0;
}