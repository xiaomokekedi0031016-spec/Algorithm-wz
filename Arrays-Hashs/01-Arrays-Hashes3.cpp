#if 0
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
//3、Two Sum
//暴力解法：使用两层循环，比较每个元素与后续元素的和是否等于目标值，如果找到满足条件的元素，则返回它们的索引；如果循环结束后没有找到满足条件的元素，则返回空数组。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
				}
            }
        }
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
					result.emplace_back(i);
                    result.emplace_back(j);
					return result;
                }
            }
        }
    }
};

//排序解法：先将数组中的元素和它们的索引存储在一个新的数组中，然后对这个新的数组进行排序。使用双指针方法，分别指向排序后的数组的开头和结尾，计算它们的和，如果等于目标值，则返回它们的原始索引；如果小于目标值，则将左指针向右移动；如果大于目标值，则将右指针向左移动。最后，如果循环结束后没有找到满足条件的元素，则返回空数组。
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for(int i = 0; i < nums.size(); ++i) {
            A.emplace_back(nums[i], i);
		}
		sort(A.begin(), A.end());
        int left = 0;
		int right = A.size() - 1;
        while(left < right) {
            int sum = A[left].first + A[right].first;
            if (sum == target) {
                return { A[left].second, A[right].second };
            }
            else if(sum < target){
                left++;
            }
            else {
                right--;
            }
		}
        return {};
    }
};

//哈希表解法：使用一个哈希表来存储已经访问过的元素及其索引，在遍历数组时，计算当前元素与目标值的差值，并检查这个差值是否存在于哈希表中，如果存在，则返回当前元素的索引和差值对应的索引；如果不存在，则将当前元素及其索引添加到哈希表中。最后，如果循环结束后没有找到满足条件的元素，则返回空数组。
//二次循环：第一次循环将数组中的元素和它们的索引存储在一个哈希表中，第二次循环遍历数组，计算当前元素与目标值的差值，并检查这个差值是否存在于哈希表中，如果存在且不是当前元素本身，则返回当前元素的索引和差值对应的索引；如果不存在，则继续循环。最后，如果循环结束后没有找到满足条件的元素，则返回空数组。
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
			int diff = target - nums[i];
            if(seen.count(diff)&& seen[diff]!= i) {
                return { i, seen[diff] };
			}
        }
    }
};

class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
			int diff = target - nums[i];
            if (seen.find(diff) != seen.end()) {
                return { min(i, seen[diff]), max(i,seen[diff])};
            }
			seen[nums[i]] = i;
        }
    }
};

int main() {
	vector<int> nums = { 2, 7, 11, 15 };
	Solution solution;
    vector <int> result = solution.twoSum(nums, 9);
    for (int index : result) {
        cout << index << " ";
	}
    cout << endl;

	Solution1 solution1;
	vector <int> result1 = solution1.twoSum(nums, 9);
    for (int index : result1) {
        cout << index << " ";
	}
    cout << endl;

    Solution2 solution2;
    vector <int> result2 = solution2.twoSum(nums, 9);
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    Solution3 solution3;
    vector <int> result3 = solution3.twoSum(nums, 9);
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    Solution4 solution4;
    vector <int> result4 = solution4.twoSum(nums, 9);
    for (int index : result4) {
        cout << index << " ";
    }
    cout << endl;

	return 0;
}

#endif