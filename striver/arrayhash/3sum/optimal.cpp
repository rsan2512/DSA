#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threesum(vector<int>& arr,int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        //skip the duplicate array
        if(i>0 && arr[i]==arr[i-1]) continue;
        int left=i+1;
        int right=n-1;
        while(left<right){
            int sum=arr[i]+arr[left]+arr[right];
            if(sum>0){
                right--;
            }
            else if(sum<0){
                left++;
            }
            else{
                ans.push_back({arr[i],arr[left],arr[right]});
                left++;right--;
                while(left<right && arr[left]==arr[left-1]) left++; // for skipping left pointer duplicates
                while(left<right && arr[right]==arr[right+1])right--; // skips right pointer duplicate
            }
        }
    }return ans;
}
int main(){
    vector<int> ques = {-3,-1,0,1,2,4};
    int n = ques.size();
    vector<vector<int>> ans= threesum(ques,n);
    for(auto &triplet: ans){
        for(auto &nums : triplet){
            cout << nums << " ";
        }
        cout<< endl;
    }
    return 0;
}