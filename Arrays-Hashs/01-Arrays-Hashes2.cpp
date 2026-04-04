#if 0
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//2、Valid Anagram
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 :
//输入 : s = "rat", t = "car"
//输出 : false

//哈希图解法：使用两个哈希表来统计字符串s和t中每个字符出现的次数，然后比较两个哈希表是否相等，如果相等则返回true，否则返回false。
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
		}
		unordered_map<char, int> CountS;
		unordered_map<char, int> CountT;
        for(int i =0 ; i < s.length(); ++i) {
            CountS[s[i]]++;
            CountT[t[i]]++;
		}
		return CountS == CountT;

    }
};


int main() {
    string s = "abca";
    string t = "bcaa";

    Solution1 solution1;
    bool result1 = solution1.isAnagram(s, t);
    cout << boolalpha << result1 << endl;  //输出: true


	return 0;
}
#endif