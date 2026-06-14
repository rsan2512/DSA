#include <bits/stdc++.h>
using namespace std;

class Disjoint {
private:
    vector<int> rank, parent;

public:
    Disjoint(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findPar(int u) {
        if (u == parent[u])
            return u;

        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int removeStones(vector<vector<int>>& stones) {

    int maxRow = 0, maxCol = 0;

    for (auto &it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    // +2 because columns start from maxRow+1
    Disjoint ds(maxRow + maxCol + 2);

    unordered_set<int> usedNodes;

    for (auto &it : stones) {

        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;

        ds.unionByRank(nodeRow, nodeCol);

        usedNodes.insert(nodeRow);
        usedNodes.insert(nodeCol);
    }

    int components = 0;

    for (auto node : usedNodes) {
        if (ds.findPar(node) == node)
            components++;
    }

    return stones.size() - components;
}

int main() {

    vector<vector<int>> stones = {
        {0,0},
        {0,1},
        {1,0},
        {1,2},
        {2,1},
        {2,2}
    };

    cout << "Maximum stones removed = "
         << removeStones(stones) << endl;

    return 0;
}