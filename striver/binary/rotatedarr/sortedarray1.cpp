#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums,int k){
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==k)return mid;
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
    }return -1;
}
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, target);

    cout << result << endl;

    return 0;
}