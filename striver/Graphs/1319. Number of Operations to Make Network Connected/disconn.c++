// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

#include <bits/stdc++.h>
using namespace std;

class Disjoint{
private:
     vector<int> rank,parent;
public:
    Disjoint(int n){
        rank.resize(n,0);
        parent.resize(n);

        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findPar(int u){
        if(u==parent[u]) return u;

        else return parent[u]=findPar(parent[u]);
    }

    bool unionByRank(int u,int v){
        int up_u=findPar(u);
        int up_v=findPar(v);

        if(up_u == up_v) return false;

        if(rank[up_u]>rank[up_v]){
            parent[up_v]=up_u;
        }
        else if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }
        else{
            parent[up_u]=up_v;
            rank[up_v]++;
        }
        return true;
    }

    int disconn(){
        int k=0;
        for(int i=0;i<rank.size();i++){
            if(findPar(i)==i){
                k++;
            }
        }return k-1;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int ex_ed=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(!ds.unionByRank(u,v)){
                ex_ed++;
            }
        }
        int dis=ds.disconn();
        if(dis<=ex_ed) return dis; 
        return -1;
    }
};
main(){
    Solution sol;
    int n =6;
    vector<vector<int>> connections={
        {0,1},
        {0,2},
        {0,3},
        {1,2}
    };
    int r=sol.makeConnected(n,connections);
    cout<< "N.o of cables  : " << r;
    
}