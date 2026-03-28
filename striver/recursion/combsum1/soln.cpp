#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // arr   = input array
    // idx   = current index we are at
    // tar   = remaining target (counts down to 0)
    // ans   = stores all valid combinations
    // combin= current combination being built
    void getAllCombinations(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
        
        // base case: reached end of array
        if (idx == arr.size()) {
            if (tar == 0)         // valid combination found
                ans.push_back(combin);
            return; //if not found then also return
        }

        // PICK arr[idx] — only if it doesnt exceed remaining target
        // stay at same index (i) because we can reuse elements
        if (arr[idx] <= tar) {
            combin.push_back(arr[idx]);
            getAllCombinations(arr, idx, tar - arr[idx], ans, combin);
            combin.pop_back();    // backtrack — undo the pick
        }

        // NOT PICK arr[idx] — move to next index
        getAllCombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(arr, 0, target, ans, combin);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // print all combinations
    for (vector<int>& subset : result) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}