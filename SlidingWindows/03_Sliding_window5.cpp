#if 0

#include <string>
#include <iostream>
#include <vector>
using namespace std;
//5、Permutation in String
//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否
//包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
//换句话说，s1 的排列之一是 s2 的 子串 。(顺序无所谓)
//示例 1：
//输入: s1 = "ab", s2 = "eidbaooo"
//输出 : true
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
		}
		vector<int> countS1(26, 0);
        vector<int> countS2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }
        int matched = 0;
        for (int i = 0; i < 26; ++i) {
            if (countS1[i] == countS2[i]) {
                matched++;
            }
        }
        int left = 0;
        for (int right = s1.size(); right < s2.size(); ++right) {
            int index = s2[right] - 'a';
            countS2[index]++;
            if (countS2[index] == countS1[index]) {
                matched++;
            }
            else if (countS1[index] + 1 == countS2[index]) {
                matched--;
            }
            index = s2[left] - 'a';
            countS2[index]--;
            if (countS1[index] == countS2[index]) {
                matched++;
            }
            else if (countS1[index] - 1 == countS2[index]) {
                matched--;
            }
            left++;
        }
        return matched == 26;
    }
};

int main() {
	Solution sol;
	string s1 = "ab";
	string s2 = "eidbaooo";
	bool result = sol.checkInclusion(s1, s2);
	cout << boolalpha << result << endl; // Expected output: true

    return 0;
}
#endif