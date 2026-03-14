#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//leetcode 3. 无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> charIndex;
        int ans = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            charIndex[s[right]]++;
            while (charIndex[s[right]] > 1) {
                left++;
				charIndex[s[left]]--;
            }
			ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main10() {
    Solution sol;
    string s = "abcabcbb";
    int ans = sol.lengthOfLongestSubstring(s);
    cout << ans << endl; 
	return 0;
}