#if 0 
//2、子集
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; // 存储最终所有子集结果
        vector<int> tmp;         // 临时存储当前路径的子集
        dfs(nums, 0, tmp, res);  // 深度优先搜索（回溯）
        return res;
    }

    // 回溯函数：nums为原始数组，path_len为当前处理的数组下标，tmp为当前子集，res为最终结果
    void dfs(vector<int>& nums, int path_len, vector<int>& tmp, vector<vector<int>>& res) {
        if (path_len == nums.size()) {
            res.emplace_back(tmp);
            return;
        }
        tmp.emplace_back(nums[path_len]);
        dfs(nums, path_len + 1, tmp, res);
        tmp.pop_back();
        dfs(nums, path_len + 1, tmp, res);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.subsets(nums);
    for (const auto& subset : res) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif