#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			//int mid = (left + right) / 2;
			//·ÀÒç³ö
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		//return right+1;
		return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
		int start = lower_bound(nums, target);
		int end = lower_bound(nums, target + 1) - 1;
		return { start, end };
    }

};


int main12() {
	vector<int> nums = { 5,7,7,8,8,10 };
	Solution sol;
	vector<int> ans = sol.searchRange(nums, 8);
	for (int c : ans) {
		cout << c << " ";
	}

    return 0;
}