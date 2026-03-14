#if 0
//滑动窗口的本质是：用两个指针（l左边界、r右边界）维护一个「窗口」，通过动态调整窗口的左右边界，找到满足条件的最优解
#include <vector>
#include <iostream>
using namespace std;

//1、Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int maxProfit = 0;
		int left = 0, right = 1;
        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
				maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
            else {
				left = right;
            }
			right++;
        }
		return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {10,1,5,6,7,1};
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl; // Expected output: 5
    return 0;
}
#endif