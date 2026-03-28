#include <bits/stdc++.h>
using namespace std;
vector<int> majority(vector<int>& arr){
    int n=arr.size();
    int c1=0,c2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for(int i=0;i<n;i++){
        if(c1==0 && el2!=arr[i]){
            c1=1;
            el1=arr[i];
        }
        else if(c2==0 && el1!=arr[i]){
            c2=1;
            el2=arr[i];
        }
        else if(el1==arr[i]) c1++;
        else if(el2==arr[i]) c2++;
        else {
            c1--;
            c2--;
        }
    }
    c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]) c1++;
        if(el2==arr[i]) c2++;
    }vector<int> result;
    int minm=n/3+1;
    if(c1>=minm){
        result.push_back(el1);
    }
    if(c2>=minm && el1!=el2){
        result.push_back(el2);
    }
    return result;

}
main(){
    vector<int> ques ={11, 33, 33, 11, 33, 11};
    vector<int> ans=majority(ques);
    for(int x: ans){
        cout << x<<" ";
    }
    cout<<"complete";
}