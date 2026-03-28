#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> blank;  // stores all subsets
    vector<int> dummy;          // current subset being built

public:
    // i = current index in nums
    void powerset(vector<int>& nums, int i) {
        if (i >= (int)nums.size()) {
            blank.push_back(dummy); // base case: add current subset to result
            return;
        }

        // EXCLUDE nums[i] — move to next index without adding
        powerset(nums, i + 1);

        // INCLUDE nums[i] — add it and recurse
        dummy.push_back(nums[i]);
        powerset(nums, i + 1);

        // UNDO — backtrack so previous call's dummy is restored
        dummy.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        powerset(nums, 0);
        return blank;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);

    // print all subsets
    for (vector<int> subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
