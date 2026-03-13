#if 0 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

//2、three sum

//哈希表
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
		sort(nums.begin(), nums.end());// 为了去重
		unordered_map<int, int> numMap; // 存储数字和出现次数
        for (auto& c : nums) {
            numMap[c]++;
        }
        for (int i = 0; i < nums.size(); i++) {
			numMap[nums[i]]--;
			if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
            for (int j = i + 1; j < nums.size(); j++) {
                numMap[nums[j]]--;
				if (j > i + 1 && nums[j] == nums[j - 1]) continue; //去重
                int diff = -(nums[i] + nums[j]);
                if (numMap[diff]) {
					result.push_back({ nums[i], nums[j], diff });
                }
            }
            for(int j = i + 1; j < nums.size(); j++) {
                numMap[nums[j]]++;
			}   
        }
		return result;
    }
};

//双指针
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
			int left = i + 1, right = nums.size() - 1;
            while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
					result.push_back({ nums[i], nums[left], nums[right] });
                    left++;
					right--;
                    while (left < right && nums[left] == nums[left - 1]) left++; // 去重
					while (left < right && nums[right] == nums[right + 1]) right--; // 去重
                }
            }
        }
		return result;
    }
};

int main() {
	Solution solution;
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = solution.threeSum(nums);
    for(auto & triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
	}
}

#endif