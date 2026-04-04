#if 0 

//6、滑动窗口的最大值
//给定一个数组 nums 和一个整数 k，找到滑动窗口中的最大值。滑动窗口是指在数组中连续的 k 个元素。
//示例 1:
//输入: nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出: [3,3,5,5,6,7]

#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		//结果数组
		vector<int> res(n - k + 1);
		deque<int> q; //存储元素索引的双端队列
		int l = 0, r = 0;
		while (r < n) {
			while (!q.empty() && nums[r] > nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(r);
			//当队列头部的索引已经不在当前窗口范围内时，移除它
			if (l > q.front()) {
				q.pop_front();
			}
			if ((r + 1) >= k) {
				res[l] = nums[q.front()]; //当前窗口的最大值
				l++;
			}
			r++;
		}
		return res;
	}
};

int main(){
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	Solution sol;
	auto result = sol.maxSlidingWindow(nums, k);
	for (auto& num : result) {
		cout << num << " ";
	}
	return 0;
}
#endif