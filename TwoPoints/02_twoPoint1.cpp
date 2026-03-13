#if 0

#include <string>
#include <iostream>
using namespace std;

//1、Valid Palindrome

//自己想的
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;

        auto start = s.begin();
        auto end = s.end() - 1;

        while (start < end) {
            // 跳过左侧非字母数字字符
            while (start < end && !isAlphaNum(*start)) {
                start++;
            }
            // 跳过右侧非字母数字字符
            while (start < end && !isAlphaNum(*end)) {
                end--;
            }

            // 统一转小写后比较
            char left = toLower(*start);
            char right = toLower(*end);
            if (left != right) {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }

private:
    // 判断是否是字母/数字
    bool isAlphaNum(char c) {
        // 字母（大写/小写） 或 数字
        return (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
    }

    // 大写转小写
    char toLower(char c) {
        // 如果是大写字母，转小写；否则返回原字符
        if (c >= 'A' && c <= 'Z') {
            return c + 32;
        }
        return c;
    }
};

//库函数+双指针
class Solution1 {
public:
    bool isPalindrome(string s) {
        // 处理空字符串边界情况
        if (s.empty()) return true;

        auto start = s.begin();
        auto end = s.end() - 1;

        while (start < end) {
            // 1. 跳过左侧非字母数字的字符
            while (start < end && !isalnum(static_cast<unsigned char>(*start))) {
                start++;
            }
            // 2. 跳过右侧非字母数字的字符
            while (start < end && !isalnum(static_cast<unsigned char>(*end))) {
                end--;
            }

            // 3. 此时start/end指向有效字符，比较（忽略大小写）
            if (tolower(static_cast<unsigned char>(*start)) != tolower(static_cast<unsigned char>(*end))) {
                return false;
            }

            // 4. 匹配成功，向中间移动指针
            start++;
            end--;
        }
        return true;
    }
};

//反向迭代器
class Solution2 {
public:
    bool isPalindrome(string s) {
        string result;
        for (auto& c : s) {
            if (isalnum(c)) {
				result += tolower(c);
            }
        }
        return result == string(result.rbegin(), result.rend());
    }
};


int main() {
    // 定义测试用例（覆盖常见场景）
    string testCases[] = {
        "A man, a plan, a canal: Panama", // 标准回文（带标点/空格）
        "race a car",                     // 非回文
        "",                               // 空字符串
        "   ",                            // 全空格
        "12321",                          // 纯数字回文
        "0P"                              // 易出错用例（O和0区分）
    };
    int caseCount = sizeof(testCases) / sizeof(testCases[0]);

    // 初始化三个解法的对象
    Solution sol;
    Solution1 sol1;
    Solution2 sol2;

    // 遍历测试用例，测试所有解法
    for (int i = 0; i < caseCount; i++) {
        cout << "=====================================" << endl;
        cout << "测试用例 " << i + 1 << ": \"" << testCases[i] << "\"" << endl;

        // 测试自己实现的版本
        bool res = sol.isPalindrome(testCases[i]);
        cout << "Solution (自定义函数)：" << res << endl;

        // 测试库函数+双指针版本
        bool res1 = sol1.isPalindrome(testCases[i]);
        cout << "Solution1 (库函数+双指针)：" << res1 << endl;

        // 测试反向迭代器版本
        bool res2 = sol2.isPalindrome(testCases[i]);
        cout << "Solution2 (反向迭代器)：" << res2 << endl;
    }

    return 0;
}

#endif
