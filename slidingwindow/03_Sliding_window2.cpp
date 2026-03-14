#if 0

#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

//3、Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
		int left = 0;
        unordered_set<char> charSet;
        for (int right = 0; right < s.size(); right++) {
			//遇到重复字符时，移动左边界，直到窗口内没有重复字符为止
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    string s = "zxyzzt";
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}


#endif
