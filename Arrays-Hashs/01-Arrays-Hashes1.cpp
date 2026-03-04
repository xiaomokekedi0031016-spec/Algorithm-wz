#if 0
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

//1、Contains Duplicate
//暴力解法：使用两层循环，比较每个元素与后续元素是否相等，如果找到相等的元素，则返回true；如果循环结束后没有找到相等的元素，则返回false。
class Solution {
public:
	bool hasDuplicate(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; i < nums.size(); ++j) {
				if (nums[i] == nums[j]) {
					return true;
				}
			}
		}
		return false;
	}
};
//排序解法：先对数组进行排序，然后使用单层循环比较相邻元素是否相等，如果找到相等的元素，则返回true；如果循环结束后没有找到相等的元素，则返回false。
class Solution1 {
public:
	bool hasDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1]) {
				return true;
			}
		}
		return false;
	}
};
//哈希表解法：使用一个哈希表来存储已经出现过的元素，在遍历数组时，检查当前元素是否已经存在于哈希表中，如果存在，则返回true；如果不存在，则将当前元素添加到哈希表中。最后，如果循环结束后没有找到相等的元素，则返回false。
class Solution2 {
public:
	bool hasDuplicate(vector<int>& nums) {
		unordered_set<int> seen;
		for (int num : nums) {
			if (seen.count(num)) {
				return true;
			}
			seen.insert(num);
		}
		return false;
	}
};


int main() {
	//1、Contains Duplicate
	Solution solution;
	vector<int> nums = { 1, 2, 3, 1 };
	bool result = solution.hasDuplicate(nums);
	cout << boolalpha << result << endl;  //输出: true

	Solution1 solution1;
	vector<int> nums1 = { 1, 2, 3, 1 };
	bool result1 = solution1.hasDuplicate(nums1);
	cout << boolalpha << result1 << endl;  //输出: true

	Solution1 solution2;
	vector<int> nums2 = { 1, 2, 3, 4 };
	bool result2 = solution1.hasDuplicate(nums2);
	cout << boolalpha << result2 << endl;  //输出: false

	return 0;
}
#endif