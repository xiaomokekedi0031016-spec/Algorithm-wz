#if 1
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//2、Valid Anagram
//排序解法：将字符串s和t进行排序，然后比较排序后的字符串是否相等，如果相等则返回true，否则返回false。
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;

/*        
        for(int i =0; i < s.length(); ++i) {
            if (s[i] != t[i]) {
                return false;
            }
		} 
*/  
    }
};

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
        
/*
        for (auto s : CountS) {
			char st = s.first;
			int sp = s.second;
            if (CountT[st] != sp) {
                return false;
            }
        }

        for (auto t : CountT) {
			char tt = t.first;
            int tp = t.second;
            if (CountS[tt] != tp) {
                return false;
			}
        }
*/
        return true;

    }
};

//数组哈希表解法：使用一个长度为52的数组来统计字符串s和t中每个字符出现的次数，然后比较两个数组是否相等，如果相等则返回true，否则返回false。

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

		vector<int> count(52, 0);
        for (int i = 0; i < s.length(); ++i) {
			char a = s[i];
            char b = t[i];
            if (a >= 'A' && a <= 'Z') {
                count[a - 'A']++;          // 大写放 0~25
            }
            else {
                count[a - 'a' + 26]++;      // 小写放 26~51
            }

            if(b >= 'A' && b <= 'Z') {
                count[b - 'A']--;          // 大写放 0~25
            }
            else {
                count[b - 'a' + 26]--;      // 小写放 26~51
			}   
        }
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "abca";
    string t = "bcaa";

	Solution solution;
	bool result = solution.isAnagram(s, t);
	cout << boolalpha << result << endl;  //输出: true

    Solution1 solution1;
    bool result1 = solution1.isAnagram(s, t);
    cout << boolalpha << result1 << endl;  //输出: true

    Solution1 solution2;
    bool result2 = solution2.isAnagram(s, t);
    cout << boolalpha << result2 << endl;  //输出: true

	return 0;
}
#endif