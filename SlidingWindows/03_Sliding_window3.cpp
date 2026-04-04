#if 0

#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//3、Longest Repeating Character Replacement
//ABBC
//hashset
class Solution {
public:
	int characterReplacement(string s, int k) {
		//去重
		unordered_set<char> charSet(s.begin(), s.end());
		int maxLength = 0;
		for (auto& c : charSet) {
			int l = 0;//左边界
			int count = 0;//窗口中c的数量
			for (int r = 0; r < s.size(); r++) {
				if (s[r] == c) {
					count++;
				}
				//窗口大小 - c的数量 > k，说明需要替换的字符超过k了，移动左边界
				while ((r - l + 1) - count > k) {
					if(s[l] == c) {
						count--;
					}
					l++;
				}
				maxLength = max(maxLength, r - l + 1);
			}
		}
		return maxLength;
	}
};

//hashmap
class Solution {
public:
	int characterReplacement(string s, int k) {
		unordered_map<char, int> charMap;//去重
		int l = 0;
		int res = 0;
		int maxLength = 0;//窗口内出现次数最多的字符数量
		for (int r = 0; r < s.size();r++) {
			//统计窗口右边界字符出现的数量
			charMap[s[r]]++;
			maxLength = max(maxLength, charMap[s[r]]);//计算窗口内出现次数最多的字符数量
			//窗口大小 - 出现次数最多的字符数量 > k，说明需要替换的字符超过k了，移动左边界
			while ((r - l + 1) - maxLength > k) {
				charMap[s[l]]--;
				l++;
			}
			res = max(res, r - l + 1);
		}
		return res;
	}
};


int main() {
	Solution sol;
    string s = "ABBB";
	//string s = "AAABABB";
	int k = 1;
	int result = sol.characterReplacement(s, k);
	cout << "Length of longest substring after replacement: " << result << endl; // Expected output: 5
}

#endif