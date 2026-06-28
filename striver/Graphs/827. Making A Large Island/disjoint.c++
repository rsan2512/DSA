#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {        //constructor to intialize
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {   // find ultimate parent
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;   //already in same component
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {  // union by size
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
    bool isValid(int newr,int newc,int n){
        return newr >= 0 && newc>=0 && newr<n && newc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n =grid.size();
        DisjointSet ds(n*n);        //we use n*n because we are converting 2d grid into 1d array and then we will use disjoint set to find the largest island
        
        
        for(int r=0;r<n;r++){   //collect all 1 and create components by using union by size
            for(int c =0 ; c<n ; c++){
                if(grid[r][c] == 0) continue;
                int dr[4] ={0,0,1,-1};
                int dc[4] ={1,-1,0,0};
                for(int i=0;i<4;i++){           //traverse all 4 directions and check if it is valid and if it is 1 then union by size
                    int newr= r + dr[i];
                    int newc= c + dc[i];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo= r*n + c;                //nodeno is adj cell number in 1d array
                        int adjnodeNo= newr*n + newc;
                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }
        }
        int mx = 0; 
        for(int r=0;r<n;r++){               //traverse all cells and if it is 0 then check all 4 directions
            for(int c=0;c<n;c++){           // and find the size of the components and add 1 to it and update the max size
                if(grid[r][c]==1) continue;
                int dr[4] ={0,0,1,-1};
                int dc[4] ={1,-1,0,0};
                set<int> components;        //use set to avoid duplicate components
                for(int i=0;i<4;i++){
                    int newr= r + dr[i];
                    int newc= c + dc[i];
                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc]==1){
                            int nodeNo= newr*n + newc;
                            components.insert(ds.findUPar(nodeNo));
                        }
                    }
                }
                int sizeTotal =0;       
                for(auto it: components){
                    sizeTotal+= ds.size[it];
                }
                mx= max(mx,sizeTotal+1);        //use max to find the maximum size of the island
            }
        }
        for(int cell=0;cell<n*n;cell++){            //if there is no 0 in the grid then return the size of the largest component
            mx=max(mx,ds.size[ds.findUPar(cell)]);
        }
        return  mx;
    }
};
int main(){
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    Solution sol;
    int result = sol.largestIsland(grid);
    cout << "Largest Island Size: " << result << endl;
    return 0;
}