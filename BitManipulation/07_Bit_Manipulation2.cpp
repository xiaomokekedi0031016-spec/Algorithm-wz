#if 0
//2、Number of 1 Bits
//n & (n-1) 的作用就是 把 n 的最右边的 1 置为 0，其他位保持不变
//n = 1100
//n - 1 = 1011
//n & (n - 1) = 1000
/*
给定一个正整数 n，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 设置位 的个数（也被称为汉明重量）。
示例 1：
输入：n = 11
输出：3
解释：输入的二进制串 1011 中，共有 3 个设置位。
示例 2：
输入：n = 128
输出：1
解释：输入的二进制串 10000000 中，共有 1 个设置位。
*/

#include <cstdint>
#include <iostream>
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int res = 0;
        while (n) {
			n &= (n - 1);
            res++;
        }
        return res;
    }
};

int main() {
    // 测试用例
    uint32_t n = 11; // 二进制表示为 1011
    Solution sol;
    int count = sol.hammingWeight(n);
    std::cout << "数字 " << n << " 的二进制表示中 1 的个数是: " << count << std::endl;
    return 0;
}   

#endif