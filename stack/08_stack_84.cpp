#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            left[stk.top()] = -1;
            stk.pop();
        }

        vector<int> right(n, n);
        stk = stack<int>(); // 清空栈
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            right[stk.top()] = n;
            stk.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                right[st.top()] = i;
                st.pop();//把左边所有比当前柱子高的柱子都删掉 >> 此时栈剩下左边比当前柱子矮的柱子
            }
            if (!st.empty()) {
				left[i] = st.top();//栈顶就是离当前柱子最近的左边比它矮的柱子
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1); // 最后大火收汁，用 -1 把栈清空
        stack<int> st;
        st.push(-1); // 在栈中只有一个数的时候，栈顶的「下面那个数」是 -1，对应 left[i] = -1 的情况
        int ans = 0;
        for (int right = 0; right < heights.size(); right++) {
            int h = heights[right];
            while (st.size() > 1 && heights[st.top()] >= h) {
                int i = st.top(); // 矩形的高（的下标）
                st.pop();
                int left = st.top(); // 栈顶下面那个数就是 left
                ans = max(ans, heights[i] * (right - left - 1));
            }
            st.push(right);
        }
        return ans;
    }
};


int main08() {
    //Solution
    vector<int> A = {2,5,3,6};
    Solution sol;
    int res = sol.largestRectangleArea(A);
    cout << "res:" <<res << endl;

	//Solution1
    vector<int> B = { 2,4,3,5 };
    Solution1 sol1;
    res = sol1.largestRectangleArea(B);
    cout << "res:" << res << endl;

    //Solution2
    vector<int> C = { 5, 6, 2 };
    Solution2 sol2;
    res = sol2.largestRectangleArea(C);
    cout << "res:" << res << endl;

    return 0;
}
