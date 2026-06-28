#include <bits/stdc++.h>
using namespace std;

class Disjoint {
private:
    vector<int> parent, rank;

public:

    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {

        if(parent[node] == node)
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv)
            return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        Disjoint ds(n);

        unordered_map<string,int> mailToAccount;

        // STEP 1
        // Connect accounts having same email

        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if(mailToAccount.find(mail) == mailToAccount.end()) {

                    mailToAccount[mail] = i;
                }
                else {

                    ds.unionByRank(i, mailToAccount[mail]);
                }
            }
        }

        // STEP 2
        // Gather mails according to DSU parent

        vector<vector<string>> mergedMails(n);

        for(auto &it : mailToAccount) {

            string mail = it.first;

            int accountNo = it.second;

            int parent = ds.findPar(accountNo);

            mergedMails[parent].push_back(mail);
        }

        // STEP 3
        // Build answer

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {

            if(mergedMails[i].size() == 0)
                continue;

            sort(mergedMails[i].begin(),
                 mergedMails[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto &mail : mergedMails[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
// Driver function
int main() {
    // Input accounts
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    // Create Solution object
    Solution obj;

    // Call function
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    // Print output
    for (auto &acc : ans) {
        cout << acc[0] << ":";
        for (int i = 1; i < acc.size(); i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}