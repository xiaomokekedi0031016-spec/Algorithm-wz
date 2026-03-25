#if 0 
//4、Daily Temperatures
//示例 1:
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
//这里使用单调递减栈，因为题目要求是找到第一个比当前温度高的日子，所以我们需要维护一个单调递减的栈来存储温度和对应的索引。
//单调递减栈：栈中元素从栈底到栈顶 依次递减，即栈顶元素最小。常用于快速找到“下一个更大元素”。

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> result(temperatures.size(), 0);
		stack<pair<int, int>> stack;
		for (int i = 0; i < temperatures.size(); ++i) {
			int t = temperatures[i];
			while (!stack.empty() && t > stack.top().first) {
				//result[stack.top().second] = i - stack.top().second;
				//stack.pop();
				auto pair = stack.top();
				stack.pop();
				result[pair.second] = i - pair.second;
			}
			stack.push({ t, i });//存储数和索引
		}
		return result;
    }
};

int main() {
	vector<int> vec{ 73,74,75,71,69,72,76,73 };
	Solution sol;
	auto result = sol.dailyTemperatures(vec);
	for (auto& res : result) {
		cout << res << " ";
	}

}
#endif