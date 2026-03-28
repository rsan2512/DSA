#include <bits/stdc++.h>
using namespace std;
#include <vector>
vector<vector<int>> threesum(vector<int>& arr,int size){
    set<vector<int>> ans;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }
        }
    }vector<vector<int>> res(ans.begin(),ans.end());
    return res;
}
int main(){
    vector<int> arr ={-3,-1,0,1,2,4};
    int size =arr.size();
    vector<vector<int>> res=threesum(arr,size);
    for(auto &triplet: res){
        for(auto &num : triplet)
            cout << num << " ";
        cout << endl;
    }
}