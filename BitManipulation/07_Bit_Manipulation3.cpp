#if 0

//3、Counting Bits
//给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
		vector<int> ans(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			int num = i;
			while (num) {
				num &= (num - 1);
				ans[i]++;
			}
		}
		return ans;
    }
};

int main() {
	// 测试用例
	int n = 5; // 输入整数 n
	Solution sol;
	vector<int> result = sol.countBits(n);
	
	cout << "从 0 到 " << n << " 的每个整数的二进制表示中 1 的个数分别是: ";
	for (int i = 0; i <= n; ++i) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}

#endif