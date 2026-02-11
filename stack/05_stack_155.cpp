/*
155. 最小栈
中等

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
*/
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class MinStack {
public:
    MinStack() {
		min_stack.push(INT_MAX);
    }

    void push(int val) {
		data_stack.push(val);
        min_stack.push(min(val, min_stack.top()));
    }

    void pop() {
		data_stack.pop();
		min_stack.pop();
    }

    int top() {
        return data_stack.top();
    }

    int getMin() {
		return min_stack.top();
    }
    
private:
    std::stack<int> data_stack;
	std::stack<int> min_stack;
};

int main05() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);

	cout << minStack.getMin() << endl; // 返回 -3.
	minStack.pop();
	cout << minStack.top() << endl;    // 返回 0.
	cout << minStack.getMin() << endl; // 返回 -2.

    return 0;
}