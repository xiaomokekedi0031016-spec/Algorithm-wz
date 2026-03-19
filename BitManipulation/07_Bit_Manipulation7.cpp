#if 0 
//7、 Reverse Integer
//题目描述：给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。如果反转后整数超过 32 位的有符号整数范围 [?2^31, 2^31 ? 1] ，就返回 0。
//示例 1：
//输入：x = 123
//输出：321
//示例 2：
//Input: x = 1234236467
//Output : 0

#include <iostream>
class Solution {
public:
    int reverse(int x) {
        int MAX = 2147483647; // 2^31 - 1
        int MIN = -2147483648; // -2^31
        int res = 0;
        while (x != 0) {
            int digit = x % 10;// 获取最后一位数字
            x = x / 10;// 去掉最后一位数字

            // 检查是否会溢出
            if (res < MIN / 10 || res > MAX / 10) {
                return 0;
            }
            if ((res == MAX / 10 && digit > MAX % 10) ||
                (res == MIN / 10 && digit < MIN % 10)) {
                return 0;
            }

            res = res * 10 + digit;// 将当前结果乘以10并加上最后一位数字
        }
        return res;
    }
};

int main() {
	Solution sol;
	int x = 123; // 输入整数
	int reversed = sol.reverse(x);
	std::cout << "整数 " << x << " 反转后的结果是: " << reversed << std::endl;
}


#endif