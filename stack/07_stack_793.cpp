#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//leetCode 793. 每日温度 >> 单调栈 >> 遇到更大的元素就出栈，记录距离

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) {
            return {};
        }
        vector<int> ans(temperatures.size());
        stack<int> t;

        for (size_t i = 0; i < temperatures.size(); i++) {
            const int x = temperatures[i];
            while (!t.empty() && temperatures[t.top()] < x) {
                ans[t.top()] = i - t.top();
                t.pop();
            }
            t.push(i);
        }
        while (!t.empty()) {
            ans[t.top()] = 0;
            t.pop();
        }

        return ans;
    }
};

int main07() {
    vector<int> A = {73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int> res = sol.dailyTemperatures(A);
    for (int index : res) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}