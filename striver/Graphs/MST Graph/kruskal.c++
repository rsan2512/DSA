#include <bits/stdc++.h>
using namespace std;

class disjoint
{
private:
    vector<int> rank,par;
public:
    disjoint(int x){  // constructor 
        rank.resize(x+1);
        par.resize(x+1);
        for(int i=1;i<x;i++){
            par[i]=i;
            rank[i]=0;
        }
    }

    int findpar(int v){
        if(par[v]==v) return v;
        else 
            return par[v]=findpar(par[v]);
    }

    bool ubyrank(int u,int v){
        int u_upar=findpar(u);
        int v_upar=findpar(v);
        
        if(u_upar==v_upar) return false; // means  they belong to same component
        if(rank[u_upar]>rank[v_upar]){
            par[v_upar]=u_upar;
        }
        else if(rank[u_upar]<rank[v_upar]){  
            par[u_upar]=v_upar;    
        }
        else{   // if rank of both parents are same
            par[u_upar]=v_upar;
            rank[u_upar]++;
        }return true;
    }
};

class kruskal{
    public:
    int krusalgo(int V,vector<vector<int>> &edges){
        sort(edges.begin(),edges.end());  // edges={wt,u,v}  undirected
        int wt=0;
        disjoint dis(V);
        for(auto it : edges ){
            int  e=it[0],u=it[1],v=it[2];
            if(dis.ubyrank(u,v)){  // if the functn returns true then the corresponding wt is added else it is already present in component
                wt+=e;
            }
        }return wt;
    }
};

main(){
    vector<vector<int>> edges={
        {1,1,4},
        {2,1,2},
        {3,2,3},
        {3,2,4},
        {4,1,5},
        {5,3,4},
        {7,2,6},
        {8,3,6},
        {9,4,6}
    };
    int V=6;
    kruskal ks;
    int edw=ks.krusalgo(V,edges);
    cout << "The mst wt is :" << edw ;  //17

}