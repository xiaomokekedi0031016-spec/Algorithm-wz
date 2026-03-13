#if 0
//8、Longest Consecutive Sequence
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//哈希集合
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //基于范围的构造函数 >> unordered_set具有去重功能
        unordered_set<int> setNum(nums.begin(), nums.end());
        int longest = 0;
        for (auto& str : setNum) {
            if(setNum.find(str - 1) == setNum.end()) {
                int length = 1;
                while (setNum.find(str + length) != setNum.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};

//哈希map
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapNum;
        int longest = 0;
        for (auto& num : nums) {
            while (!mapNum[num]) {
				//mapNum[t]表示以t为中心的最长连续序列的长度，初始值为0
                mapNum[num] = mapNum[num + 1] + mapNum[num - 1] + 1;
                //num-mapNum[t-1]表示最左端点 >> 公式:最左端点位置 = 当前位置 - 序列长度
                mapNum[num - mapNum[num - 1]] = mapNum[num];
				mapNum[num + mapNum[num + 1]] = mapNum[num];
				longest = max(longest, mapNum[num]);
            }
        }
        return longest;
    }
};


int main() {
    vector<int> vec = { 3,1,4,8,6,5,2 };

    Solution sol;
    int res = sol.longestConsecutive(vec);
    cout << "res:" << res << "\n";


    Solution1 sol1;
    int res1 = sol1.longestConsecutive(vec);
    cout << "res1:" << res1;

    return 0;
}

#endif