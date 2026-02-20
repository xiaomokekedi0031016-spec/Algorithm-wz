#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // int findMin(vector<int>& nums) {
    //     int left = 0, right = nums.size() - 1;

    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] > nums[right]) {
    //             left = mid + 1;
    //         } else {
    //             right = mid;
    //         }
    //     }
    //     return left;  // 最小值下标
    // }
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 || nums.front() < nums.back()) {
            return 0;
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
        return left;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findMin(nums);

        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        }
        else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};

int main() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    Solution sol;
    int ans = sol.search(nums, 2);
    cout << ans << endl;
    return 0;
}