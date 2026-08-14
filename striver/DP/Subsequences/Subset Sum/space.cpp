#include <bits/stdc++.h>
using namespace std;

// t.c = O(n*sum) s.c = O(sum)

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1,0);
        
        prev[0] = true;
        prev[arr[0]] = true;
        
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
};

int main(){
    Solution obj;
    vector<int> arr = {1,2,3,4};
    int sum = 6;
    cout<<obj.isSubsetSum(arr,sum);
}