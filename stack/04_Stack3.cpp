#if 0

//3、Evaluate Reverse Polish Notation
//示例 1：
//输入：tokens = ["2", "1", "+", "3", "*"]
//输出：9
//解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//示例 2：
//输入：tokens = ["4", "13", "5", "/", "+"]
//输出：6
//解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6


//思路：
//创建一个空堆。
//对于每个标记：
//如果是数字，就将其转换为整数并推入堆栈。
//如果它是算符：
//弹出前两位数字。
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const auto& str : tokens) {
            if (str == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b + a);
            }
            else if (str == "-") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b - a);
            }
            else if (str == "*") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b * a);
            }
            else if (str == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b / a);
            }
            else {
                stack.push(stoi(str));
            }
        }
        return stack.top();
    }
};

int main() {
	Solution solution;
	vector<string> tokens1 = { "2", "1", "+", "3", "*" };
	vector<string> tokens2 = { "4", "13", "5", "/", "+" };
	cout << solution.evalRPN(tokens1) << endl; // 输出: 9
	cout << solution.evalRPN(tokens2) << endl; // 输出: 6

	return 0;
}

#endif