#if 0
//4、Reverse Bits
//颠倒给定的 32 位无符号整数的二进制位。
//示例 1：
//输入：n = 00000010100101000001111010011100
//输出：964176192 (00111001011110000010100101000000)

/*
整数	    二进制
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000

*/

/*
(n >> i) & 1 → 取出 n 的第 i 位
(bit << (31-i)) → 把这一位放到反转后的位置
*/
#include <cstdint>
#include <iostream>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i < 32; ++i) {
			uint32_t bit = (n >> i) & 1;
			res += (bit << (31 - i));
		}
		return res;
    }
};

int main() {
	// 测试用例
	uint32_t n = 43261596; // 输入的 32 位无符号整数
	Solution sol;
	uint32_t reversed = sol.reverseBits(n);
	std::cout << "输入的二进制数颠倒后的结果是: " << reversed << std::endl;
	return 0;
}

#endif