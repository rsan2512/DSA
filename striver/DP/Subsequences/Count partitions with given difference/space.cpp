#include <bits/stdc++.h>
using namespace std;

// T.c = O(n*sum) s.c = O(sum)
int mod = (int)(1e9 +7);
class Solution {
  public:
  int countSub(int n,int tar, vector<int>& arr){
         vector<int> prev(tar + 1, 0);
        
        if(arr[0] == 0) prev[0] =2;
        else prev[0]=1;

        if(arr[0]!=0 && arr[0]<=tar) prev[arr[0]] =1; 
        
        for(int i =1;i<n;i++){
            vector<int> curr(tar+1,0);
            for(int j = 0;j<=tar;j++){
                int ntake = prev[j];
                int take = 0;
                if(arr[i]<=j)
                    take = prev[j - arr[i]];
                 curr[j]=(take + ntake)% mod;
            }prev = curr;
        }
        return prev[tar];
    }
   int countPartitions(int n, int diff, vector<int>& arr) {
        int tsum=0;
        for(int i =0;i<n;i++)tsum+=arr[i];
        if(tsum - diff<0 || (tsum-diff) % 2) return 0;
        int target = (tsum - diff) / 2;
        return countSub(n,target,arr);
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int diff = 1;
    cout<<obj.countPartitions(arr.size(),diff,arr); // ans = 5
}