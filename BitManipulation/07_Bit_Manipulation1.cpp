#if 0 
//1、Single Number
//题目描述：给你一个整数数组 nums ，除某个元素仅出现一次外，其余每个元素都恰出现两次。请你找出并返回那个只出现了一次的元素。
//示例 1：
//输入：nums = [4，4，2 ,2,1]
//输出：1

//异或运算：对于任何整数 x，都有 x ^ x = 0 和 x ^ 0 = x。对于数组中的每个元素，进行异或运算，最终结果就是那个只出现一次的元素。

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(const auto& num : nums) {
             res^= num;
		}  
        return res;
    }
};


int main() {
    // 测试用例
    vector<int> nums = { 7, 6, 6, 7, 8 };

    Solution sol;
    int single = sol.singleNumber(nums);

    cout << "数组中只出现一次的数字是: " << single << endl;

    return 0;
}
#endif