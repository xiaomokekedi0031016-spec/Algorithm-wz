#if 0 
//4、Group Anagrams
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

//排序法：将每个字符串进行排序，然后使用一个哈希表来存储排序后的字符串作为键，原始字符串作为值的列表。最后，返回哈希表中的所有值列表。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> groups;
        for (int i = 0; i < strs.size(); ++i) {
			string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
			groups[sortedStr].emplace_back(strs[i]);
        }
		vector<vector<string>> result;
        for (auto& group : groups) {
			result.emplace_back(group.second);
        }
        return result;
    }
};

//哈希表法：使用一个哈希表来存储每个字符串的字符计数作为键，原始字符串作为值的列表。最后，返回哈希表中的所有值列表。
class Solution1 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> res;	
		for (int i = 0; i < strs.size(); ++i) {
			vector<int> count(26, 0);
			for (char c : strs[i]) {
				count[c - 'a']++;
			}
			string key = string();
			for (int i = 0; i < 26; ++i) {
				key += to_string(count[i]) + "#";
			}
			res[key].emplace_back(strs[i]);
		}
		vector<vector<string>> result;	
		for (auto& group : res) {
			result.emplace_back(group.second);
		}
		return result;
	}
};

int main() {
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

	Solution solution;
	vector<vector<string>> result = solution.groupAnagrams(strs);
	for (const auto& group : result) {
		for (const auto& str : group) {
			cout << str << " ";
		}
		cout << endl;
	}

	Solution1 solution1;
	vector<vector<string>> result1 = solution1.groupAnagrams(strs);
	for (const auto& group : result) {
		for (const auto& str : group) {
			cout << str << " ";
		}
		cout << endl;
	}

    return 0;
}

#endif