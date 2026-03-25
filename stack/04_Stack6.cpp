#if 0

//6、Largest Rectangle In Histogram
//单调增加栈
#include<vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
		int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
  //      for (int i = 0; i < n; ++i) {
  //          while (!stk.empty() && heights[i] <= heights[stk.top()]) {
		//		stk.pop();
  //          }
  //          if (!stk.empty()) {
  //              left[i] = stk.top();
  //          }
		//	stk.push(i);  
  //      }

		//while(!stk.empty()) stk.pop();

  //      for (int i = n-1; i >=0; --i) {
  //          while (!stk.empty() && heights[i] <= heights[stk.top()]) {
  //              stk.pop();
  //          }
  //          if (!stk.empty()) {
  //              right[i] = stk.top();
  //          }
  //          stk.push(i);
  //      }
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (!stk.empty() && heights[stk.top()] >= h) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }



		int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }
		return maxArea;
    }
};

int main() {
    vector<int> vec{ 2,1,5,6,2,3 };
    Solution sol;
    auto result = sol.largestRectangleArea(vec);

	cout << result << endl;
    return 0;
}

#endif