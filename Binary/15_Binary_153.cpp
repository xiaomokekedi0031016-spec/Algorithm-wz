#if 0
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 || nums.front() < nums.back()) {
            return nums.front();
        }
        int mid = 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.front()) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};

int main15()
{
    vector<int> nums = { 3,4,5,1,2 };
    Solution sol;
    int ans = sol.findMin(nums);
    cout << ans << endl;
    return 0;
}

#endif