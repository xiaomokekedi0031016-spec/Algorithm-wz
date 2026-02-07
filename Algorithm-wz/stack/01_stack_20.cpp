#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

//LeetCode 20. Valid Parentheses

//只能处理一个括号类型的情况(if else)
class Solution {
public:
    bool isValid(std::string s) {
        if (s.empty()) {
            return false;
        }
        if(s.size() % 2 != 0) {
            return false;
		}
        std::stack<char> stk;
        //for (int i = 0; i < s.size(); ++i) {}
        for (char c : s) {
            if (c == '(') {
				stk.push(')');
            }
            else if(c == ')' && !stk.empty()) {
                stk.pop();
            }
            else {
                return false;
			}
        }
        return stk.empty();
    }
};

//只处理一个括号类型的情况(用count计数)

class Solution1 {
public:
    bool isValid(std::string s) {
        if (s.empty()) {
            return false;
        }
        if (s.size() % 2 != 0) {
            return false;
        }
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                ++count;
            }
            else if (c == ')') {
                --count;
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }
};  

//处理多种括号
class Solution2 {
public:
    bool isValid(std::string s) {
        if (s.empty()) {
            return false;
        }
        if(s.size() % 2 != 0) {
            return false;
        }
        std::stack<char> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push(')');
            }
            else if (c == '{') {
                stk.push('}');
            }
            else if (c == '[') {
                stk.push(']');
            }
            else if(!stk.empty() && c == stk.top()) {
                stk.pop();
            }
            else {
                return false;
            }
        }
        return stk.empty();
	}
};

//处理多种括号(抄的)
class Solution3 {
public:
    bool isValid(std::string s) {
        if (s.empty()) {
            return false;
        }
        if (s.size() % 2 != 0) {
            return false;
        }
        std::unordered_map<char, char> paren_map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
		std::stack<char> stk;
        for (char c : s) {
            if (paren_map.count(c)) {
                if (stk.empty() || stk.top() != paren_map[c]) {
                    return false;
                }
				stk.pop();
            }
            else {
				stk.push(c);
            }
        }
		return stk.empty();
    }
};

int main01() {
    //Solution
    std::string str = "()()(())";
	Solution sol;
    bool res = sol.isValid(str);
    std::cout << std::boolalpha << res << std::endl;

	//Solution1
    std::string str1 = "((()))()";
    Solution1 sol1;
    bool res1 = sol1.isValid(str1);
	std::cout << std::boolalpha << res1 << std::endl;

	//Solution2
    std::string str2 = "()[]{}({[]})";
    Solution2 sol2;
    bool res2 = sol2.isValid(str2);
    std::cout << std::boolalpha << res2 << std::endl;
	

	//Solution3
    std::string str3 = "({[()]})";
    Solution3 sol3;
    bool res3 = sol3.isValid(str3);
	std::cout << std::boolalpha << res3 << std::endl;

    return 0;
}