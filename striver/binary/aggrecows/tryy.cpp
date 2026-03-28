#include <bits/stdc++.h>
using namespace std;
bool Can_we_place(vector<int>&stalls,int cows,int d){
    int cnt=1;                          //to count the n.o of cows placed every iteration on main loop reset it to 1
    int lst_pos=stalls[0];              //store the 1st cow in 1st stall :used to store nxt posn 
    for(int i=0;i<stalls.size();i++){       //stalls running
        if(stalls[i]-lst_pos>=d){           //if dist btwn current stall and last stall then true
            cnt++;                             //increase the n.o of cows
            lst_pos=stalls[i];                  //last postn taken by current stall
        }
        if(cnt>=cows) return true;              //if cnt equals cows it satisfies so it satisfies 
    }return false;                  //if it cnt!=cows
}

int brute(vector<int>& stalls,int cows){
    sort(stalls.begin(),stalls.end());      //sort for easier calc of stalls
    int n=stalls.size(),ans;
    int max_dist=stalls.end()-stalls.begin();      //maxm dist btwn two cows placed at begin and end,if only 2 cows it can be returned
    for(int d=1;d<=max_dist;d++){                   // cheking every dist from 1 to the maxx 
        if(Can_we_place(stalls,cows,d))             //another func to place cows further or at d dist
            ans=d;                          //ans var to store dist and it stores the highest dist it can store
    }return ans;                    //return the maxm placing dist
}
int main(){
    vector<int> ques={0,3,4,7,10,9};
    int cows=4;
    int ans=brute(ques,cows);
    cout<< ans; 
}