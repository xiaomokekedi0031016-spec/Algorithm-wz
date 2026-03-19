#if 0

//6、Sum of Two Integers
//题目描述：给你两个整数 a 和 b ，不使用 运算符 + 和 - ???????，计算并返回两整数之和。
//示例 1：
//输入：a = 1, b = 2
//输出：3

/*
核心思路
a ^ b → 把两个数字按位相加，但不算进位。
(a & b) << 1 → 计算哪些位置会产生进位，并把进位“移到下一位”。
把进位加到上一步结果里。
循环直到没有进位，得到最终结果。
*/

#include <iostream>
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int val = (a & b) << 1;
			a ^= b;
			b = val;
        }
        return a;
    }
};

int main() {
    // 测试用例
    int a = 1; // 第一个整数
    int b = 2; // 第二个整数
    Solution sol;
    int sum = sol.getSum(a, b);
    std::cout << "两个整数 " << a << " 和 " << b << " 的和是: " << sum << std::endl;
    return 0;
}


#endif