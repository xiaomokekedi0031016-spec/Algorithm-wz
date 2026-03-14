#if 0

#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//3、Longest Repeating Character Replacement

//err
//ABBC
//ABBB
// 代码只允许把窗口内字符替换成左边界字符
//class Solution {
//public:
//    int characterReplacement(string s, int k) {
//        if (s.empty()) return 0; // 空字符串特殊处理
//        int n = s.size();
//        int maxLength = 0;
//        int original_k = k; // 保存原始k，避免修改后无法重置
//
//        // 遍历每个左边界
//        for (int left = 0; left < n; left++) {
//            int current_k = original_k; // 每轮左边界重置可用k
//            int right = left; // 右边界从左边界开始扩展
//
//            // 扩展右边界：不越界 + （字符相同 或 有可用k替换）
//            while (right < n) {
//                if (s[right] != s[left]) {
//                    // 字符不同，需要消耗k
//                    if (current_k <= 0) break; // k用完，停止扩展
//                    current_k--; // 消耗1个k
//                }
//                // 计算当前窗口长度并更新最大值
//                maxLength = max(maxLength, right - left + 1);
//                right++; // 继续扩展右边界
//            }
//        }
//        return maxLength;
//    }
//};

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
			res = max(maxLength, r - l + 1);
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