class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1,0);
        
        prev[0] = true;
        if (arr[0] <= sum) prev[arr[0]] = true;
        
        for(int i = 1;i<n;i++){
            vector<bool> curr(sum + 1,0);
            curr[0] = true;
            for(int tar = 1;tar<=sum;tar++){
                bool notTake = prev[tar];
                
                bool take = false;
                if(arr[i]<= tar) take = prev[tar-arr[i]];
                
                curr[tar]= take | notTake;
            }prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        if(sum %2 != 0 ) return false;
        else return isSubsetSum(nums,sum/2);
    }
};