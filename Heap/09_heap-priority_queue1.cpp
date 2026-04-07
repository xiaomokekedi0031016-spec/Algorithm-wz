#if 0
//堆是完全二叉树
//1、数组中的第K个最大元素
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆
		for (int num : nums) {
			minHeap.push(num);
			if(minHeap.size() > k) {
				minHeap.pop();
			}
		}
		return minHeap.top();
    }
};

int main() {
	Solution sol;
	vector<int> nums = {3, 2, 1, 5, 6, 4};
	int k = 2;
	cout << sol.findKthLargest(nums, k) << endl; // 输出: 5
	return 0;
}	
#endif