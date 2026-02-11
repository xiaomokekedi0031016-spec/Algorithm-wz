/*
 * 题目：给定一个数组，要找到这个数组里面每个元素右边比我大的元素的位置
 * - 注意：是右边第一个比我大的，如果有多个的话
 * - 如果没有，那么用-1表示。
 * 返回：一个数组，表示右边比我大的数的下标位置
 *
 * 输入：[5, 6]
 * 输出：[1, -1]
 * 解释：A[0] = 5，右边比我大的是A[1] = 6, 所以记录为 = 1
 *       A[1] = 6, 右边比我大的元素没有，所以记录为   = -1
 *       所以返回值是[1, -1]
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//右边第一个比我大的元素位置
class Solution {
public:
    vector<int> findRightLarge(vector<int>& A) {
        if (A.empty()) {
            return {};
        }
        // 结果数组
        vector<int> ans(A.size());

        // 注意，栈中的元素记录的是下标
        stack<int> t;

        for (size_t i = 0; i < A.size(); i++) {
            const int x = A[i];
            // 每个元素都向左遍历栈中的元素完成消除动作
            while (!t.empty() && A[t.top()] < x) {
                //cout << t.top() << endl;
                //cout << A[t.top()] << endl;
                //cout << "*****" << endl;
                // 消除的时候，记录一下被谁消除了
                ans[t.top()] = i;
				cout << t.top() << "被" << i << "消除" << endl;
                // 消除时候，值更大的需要从栈中消失
                t.pop();
            }
            // 剩下的入栈
            t.push(i);
        }
        // 栈中剩下的元素，由于没有人能消除他们，因此，只能将结果设置为-1。
        while (!t.empty()) {
            ans[t.top()] = -1;
            t.pop();
        }

        return ans;
    }
};

//右边第一个比我小的元素位置
class Solution1 {
public:
    vector<int> findRightSmall(vector<int>& B) {
        if (B.empty()) {
            return {};
        }
        vector<int> ans(B.size());
        stack<int> t;
        for (size_t i = 0; i < B.size(); ++i){
            const int x = B[i];
            while (!t.empty() && B[t.top()] > x) {
				ans[t.top()] = i;
				t.pop();
            }
			t.push(i);
        }
        while(!t.empty()) {
            ans[t.top()] = -1;
            t.pop();
		}   
		return ans;
    }
};

//左边第一个比我大的元素位置
class Solution2 {
public:
    vector<int> findLeftLarge(vector<int>& C) {
        if (C.empty()) {
            return {};
        }
        vector<int> ans(C.size());
        stack<int> t;
        for (int i = C.size() - 1; i >= 0; i--) {
			const int x = C[i];
            while (!t.empty() && C[t.top()] < x) {
                ans[t.top()] = i;
                t.pop();
            }
			t.push(i);
        }
        while (!t.empty()) {
            ans[t.top()] = -1;
            t.pop();
        }
        return ans;

    }
};

//左边第一个比我小的元素位置
class Solution3 {
public:
    vector<int> findLeftSmall(vector<int>& D) {
        if (D.empty()) {
            return {};
        }
        vector<int> ans(D.size());
        stack<int> t;
        for (int i = D.size() - 1; i >= 0; i--) {
            const int x = D[i];
            while (!t.empty() && D[t.top()] > x) {
                ans[t.top()] = i;
                t.pop();
            }
            t.push(i);
        }
        while (!t.empty()) {
            ans[t.top()] = -1;
            t.pop();
        }
        return ans;

    }
};

int main03() {
	//Solution
	vector<int> A = {73,72,71,74};
	Solution sol;
	vector<int> res = sol.findRightLarge(A);
	for (int index : res) {
		cout << index << " ";
	}
	cout << endl;

    //stack<int> stk;
	//stk.push(10);
	//stk.push(20);
	//cout << "栈顶元素:" << stk.top() << endl;

    //Solution1
    vector<int> B = { 1, 2 ,4, 9, 4, 0, 5 };
    Solution1 sol1;
    vector<int> res1 = sol1.findRightSmall(B);
    for (int index : res1) {
        cout << index << " ";
    }
    cout << endl;

    //Solution2
    vector<int> C = { 4, 6 ,9, 5, 2, 8};
    Solution2 sol2;
    vector<int> res2 = sol2.findLeftLarge(C);
    for (int index : res2) {
        cout << index << " ";
    }
    cout << endl;

    //Solution3
    vector<int> D = { 4, 6 ,9, 5, 2, 8 };
    Solution3 sol3;
    vector<int> res3 = sol3.findLeftSmall(C);
    for (int index : res3) {
        cout << index << " ";
    }
    cout << endl;

	return 0;
}