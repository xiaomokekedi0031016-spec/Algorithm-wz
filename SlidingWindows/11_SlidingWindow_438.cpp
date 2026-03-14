#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//leetcode 438. 找到字符串中所有字母异位词

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		unordered_map<char, int>charCnt;
        for (char c : p) {
            charCnt[c]++;
        }
        for (int left= 0,right = 0; right < s.size(); ++right) {
            charCnt[s[right]]--;
            while(charCnt[s[right]] < 0) {
                charCnt[s[left]]++;
                left++;
			}
            if (right - left + 1 == p.size()) {
                ans.push_back(left);
            }
        }
		return ans;
    }
};

int main() {
    Solution sol;
    string s = "abbaab";
    vector<int> ans = sol.findAnagrams(s, "ab");
    for (int c : ans) {
		cout << c << " ";
    }

    return 0;
}