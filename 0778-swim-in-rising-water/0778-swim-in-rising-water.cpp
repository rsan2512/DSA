class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

    bool isValid(int x,int y,int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    


    int swimInWater(vector<vector<int>>& grid) {
        // min heap is to used 
        // time till now ->{x,y}
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>time(n,vector<int>(n,INT_MAX)); 
        time[0][0]=grid[0][0];
        while(!pq.empty()){
            int time_till_now=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(auto it:dir){
                int new_x=x+it.first;
                int new_y=y+it.second;
                if(isValid(new_x,new_y,n)){
                    int curr_time=grid[new_x][new_y];
                    if(time[new_x][new_y]>max(curr_time,time_till_now)){
                        time[new_x][new_y]=max(curr_time,time_till_now);
                        pq.push({time[new_x][new_y],{new_x,new_y}});
                    }
                }       
            }

        }

        return time[n-1][n-1];


    }
};