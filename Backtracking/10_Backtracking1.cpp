#if  0

//递归+状态的保存叫做回溯算法

//1、全排列
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, nums, tmp);
		return res;
    }
	//res保存结果，nums是输入数组，tmp是当前的排列(临时的结果)
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp) {
        if (tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int j;
            for(j = 0; j < tmp.size(); ++j) {
				//当前元素是否在tmp数组中，如果在就跳出循环，说明这个元素已经被使用过了
                if(nums[i] == tmp[j]) {
                    break;
                }
			}
			//如果j等于tmp.size()，说明当前元素不在tmp数组中，可以使用这个元素进行下一步的递归
            if(j == tmp.size()) {
                tmp.push_back(nums[i]);
                dfs(res, nums, tmp);
                tmp.pop_back();
			}
        }
	}
};

class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(nums, tmp, res);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int num : nums) {             // 范围for，更清爽
            if (contains(tmp, num)) continue; // 抽成函数，代码变干净

            tmp.push_back(num);
            dfs(nums, tmp, res);
            tmp.pop_back();
        }
    }

    // 小工具：判断元素是否已存在
    bool contains(vector<int>& tmp, int num) {
        for (int n : tmp) {
            if (n == num) return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.permute(nums);
    for (const auto& perm : res) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

#endif