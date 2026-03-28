/*Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. 
 Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.
*/
#include <bits/stdc++.h>
using namespace std;
bool Can_Place_Cows(vector<int>&stalls,int cows,int d){
    int cnt=1;                          //to count the n.o of cows placed every iteration on main loop reset it to 1
    int lst_pos=stalls[0];              //store the 1st cow in 1st stall :used to store nxt posn 
    for(int i=1;i<stalls.size();i++){       //stalls running
        if(stalls[i]-lst_pos>=d){           //if dist btwn current stall and last stall then true
            cnt++;                             //increase the n.o of cows
            lst_pos=stalls[i];                  //last postn taken by current stall
        }
        if(cnt>=cows) return true;              //if cnt equals cows it satisfies so it satisfies 
    }return false;                  //if it cnt!=cows
}

int opt(vector<int>& stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int maxm=stalls[n-1]-stalls[0]; 
    int low=1,high=maxm,ans=0;
    while(low<=high){                   //we use binary search to decrease the search space
        int mid=(low+high)/2;
        if(Can_Place_Cows(stalls,cows,mid)){        
            ans=mid;                    //if the cows can be placed we can store the ans and update if higher value is obtained
            low=mid+1;                  //finding a higher value than mid
        }else{
            high=mid-1;                 //finding a lower value than mid
        }
    }return ans;
}
int main(){
    vector<int> ques={0,3,4,7,10};
    int cows=4;
    int ans=opt(ques,cows);
    cout<<ans;
}