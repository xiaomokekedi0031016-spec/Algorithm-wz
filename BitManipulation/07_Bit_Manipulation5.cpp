#if 0 

//5、Missing Number
//给定一个包含[0, n] 中 n 个数的数组 nums ，找出[0, n] 这个范围内没有出现在数组中的那个数。
//示例 1：
//输入：nums = [3, 0, 1]
//输出：2
//解释：n = 3，因为有 3 个数字，所以所有的数字都在范围[0, 3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
			n ^= i ^ nums[i];
		}
		return n;
    }
};

int main() {
	// 测试用例
	vector<int> nums = { 3, 0, 1 }; // 输入的数组
	Solution sol;
	int missing = sol.missingNumber(nums);
	cout << "数组中缺失的数字是: " << missing << endl;
	return 0;
}
#endif