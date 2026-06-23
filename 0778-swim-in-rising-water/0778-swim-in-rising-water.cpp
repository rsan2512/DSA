class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        priority_queue< //ele,x,y
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> vis(n,vector<bool>(n,false));

        pq.push({grid[0][0],0,0});

        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            auto mx=curr[0];
            auto x=curr[1];
            auto y=curr[2];

            if (vis[x][y]) continue;
            vis[x][y]=true;

            if(x==n-1 && y==n-1) return mx;

            for(int i=0;i<4;i++){
                int nr = x + dr[i];
                int nc = y + dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                    int newmx=max(mx,grid[nr][nc]);

                    pq.push({newmx,nr,nc});
                }
            }
        }return -1;
    }
};