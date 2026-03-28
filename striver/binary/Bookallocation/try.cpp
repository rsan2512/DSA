#include <bits/stdc++.h>
using namespace std;
int countpages(vector<int>ques,int pages){
    int n=ques.size();
    int stud=1;
    long long pagestud=0;
    for(int i=0;i<n;i++){
        if(pagestud+ques[i]<=pages){
            pagestud+=ques[i];
        }else{
            stud++;
            pagestud=ques[i];
        }
    }return stud;

}
int brute(vector<int>& ques,int stud){
    if(stud>ques.size())return -1;
    int maxm=*max_element(ques.begin(),ques.end());
    int s=0;
    for(int x:ques){
        s+=x;
    }
    for(int pages=maxm;pages<s;pages++){
        if(countpages(ques,pages)==stud){
            return pages;
        }
    }return maxm;
}
int main(){
    vector<int> ques={25, 46, 28, 49, 24};
    int stud=4;
    int ans=brute(ques,stud);
    cout<<ans;
}