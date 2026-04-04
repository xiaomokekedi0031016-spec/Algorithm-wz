#if 0
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

//1、Contains Duplicate
// 判断一个数组中是否存在重复元素，如果存在返回true，否则返回false。
//Input: nums = [1, 2, 3, 3]
//Output: true


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
	Solution1 solution2;
	vector<int> nums2 = { 1, 2, 3, 4 };
	bool result2 = solution1.hasDuplicate(nums2);
	cout << boolalpha << result2 << endl;  //输出: false

	return 0;
}
#endif