class Solution {
public:
    int rob(vector<int>& arr) {
        
        int n = arr.size();
        if(n==1) return arr[0];

        int prev1= 0,prev2=0;
        for(int idx=2;idx<=n;idx++){
            int curr = max(prev1,arr[idx-1]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        int ans = prev1;

        prev2=0;
        prev1=arr[0];
        for(int idx=2;idx<=n;idx++){
            int curr = max(prev1,arr[idx-1]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        ans = max(ans , prev2);
        return ans;

    }
};