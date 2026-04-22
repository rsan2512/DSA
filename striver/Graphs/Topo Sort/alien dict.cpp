#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indeg(V, 0);

        for(int i = 0; i < V; i++){
            for(auto it : adj[i]) indeg[it]++;
        } 

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return ans;
    } 

    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];

        for(int i = 0; i < N - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            for(int ptr = 0; ptr < len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);

        string ans = "";
        for(auto it : topo){
            ans += char(it + 'a');
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string order = obj.findOrder(dict, N, K);

    cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
//baa _> abcd->abca->cab->cad
//b->a->c