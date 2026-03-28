#include <bits/stdc++.h>
using namespace std;
// wee use two loops to get number and search for third element by making sure it exists in vector using hassets

vector<vector<int>> threesum(vector<int>& arr,int size){
    set<vector<int>> st;//set to store the elements of 2d vector in ascending order and make sure no duplicates are repeated
    for(int i=0;i<size;i++){
        set<int> hset;  // set to store the unique third digit digit it always becomes empty
        for(int j=i+1;j<size;j++){      //hset increses with ti me
            int third =-(arr[i]+arr[j]);         //hset.find() takes no time
            if(hset.find(third)!=hset.end()){   //if found then find if not then end
                vector<int> temp ={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hset.insert(arr[j]); //we insert the current in hash to check in next loops
        }
    }vector<vector<int>> res(st.begin(),st.end());
    return res;
}
int main(){
    vector<int> ques ={-3,-1,0,1,2,4};
    int size= ques.size();
    vector<vector<int>> res =threesum(ques,size);
    for(auto &triplet : res){
        for(auto &nums : triplet)
         cout<< nums << " ";
         cout<< endl;
    }
}