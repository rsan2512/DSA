#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> invtry(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> ans; 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j]){
                ans.push_back({nums[i],nums[j]});
            }
        }
    }return ans;
}
int main(){
    vector<int> nums={5,4,2,1,3};
    vector<vector<int>> ans=invtry(nums);
    for(auto x:ans){
        for(auto y:x){
            cout << y<< " ";
        }cout<<endl;
    }
}