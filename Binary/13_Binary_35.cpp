#include <iostream>
#include <vector>
using namespace std;

// 34. Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
		int left = 0;
		int right = nums.size() - 1;
        while (left <= right) {
			int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
				left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
		return left;
    }
};

int main13()
{
    vector<int> nums = { 1,3,5,6 };
    int target = 4;
    Solution sol;
    int ans = sol.searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}