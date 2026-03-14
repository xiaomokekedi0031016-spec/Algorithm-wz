#if 0
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

//4、Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
		unordered_map<char, int> countT, window;
		for (char c : t) {//统计t中每个字符的数量
			countT[c]++;
		}
		int have = 0; //窗口中满足条件的字符数量
		int need = countT.size(); //需要满足的字符种类数量
		int minLength = INT_MAX; //记录最小窗口长度
		pair<int, int> result = { -1, -1 }; //记录最小窗口的左右边界
		int l = 0;
		for (int r = 0; r < s.size(); r++) {
			window[s[r]]++;
			if (countT.count(s[r]) && countT[s[r]] == window[s[r]]) {
				have++;
			}
			while (have == need) {
				//满足子串条件，开始收缩
				if (r - l + 1 < minLength) {
					minLength = r - l + 1;
					result = { l, r };
				}
				window[s[l]]--;
				//后面条件是为了保证have的正确性，只有当窗口中某个字符数量不满足t中的要求时，才减少have
				if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
					have--;
				}
				l++;
			}
		}
		return minLength == INT_MAX ? "" : s.substr(result.first, minLength);
    }
};

int main() {
	Solution sol;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string result = sol.minWindow(s, t);
	cout << "Minimum window substring: " << result << endl; // Expected output: "BANC"

}
#endif