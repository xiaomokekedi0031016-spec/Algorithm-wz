#if 0
//2、Min Stack 
/*
实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
*/
#include <stack>
#include <iostream>
using namespace std;

class MinStack {
private:
    stack<int> minStack;
    stack<int> dataStack;

public:
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int val) {
        dataStack.push(val);
        minStack.push(min(val, minStack.top()));
    }

    void pop() {
        dataStack.pop();
        minStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}
#endif