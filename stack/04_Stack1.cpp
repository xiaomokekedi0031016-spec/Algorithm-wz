#if 0
//1、Valid Parentheses
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//栈+一堆if else
class Solution {
public:
    bool isValid(string s) {
		stack<char> stk;
        if(s.size() % 2 != 0) {
            return false;
		}
        for (const auto& c : s) {
            if (c == '(') {
                stk.push(')');
            }
            else if(c == '[') {
				stk.push(']');
			}
            else if (c == '{') {
                stk.push('}');
            }
            else if(!stk.empty() && c == stk.top()) {
                stk.pop();
            }
            else {
                return false;
            }
        }
        //return true;//err
		return stk.empty();//如果栈不空，说明有未匹配的左括号
    }
};

/*
    std::unordered_map<int, std::string> dict = {{1, "one"}, {2, "two"}};
    dict.insert({3, "three"});
    dict.insert(std::make_pair(4, "four"));
    dict.insert({{4, "another four"}, {5, "five"}});
*/

//栈+哈希表
class Solution2 {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
		stack<char> stk;
        unordered_map<char, char> paren_map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
		};
        for (const auto& c : s) {
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
        //return true;//err
        return stk.empty();
    }
};

int main() {
    string s1 = "()[]{}";
    string s2 = "((";

    Solution sol1;
    bool result1 = sol1.isValid(s1);
    bool result2 = sol1.isValid(s2);
	std::cout << "result:" << result1 << std::endl;
    std::cout << "result:" << result2 << std::endl;

    Solution2 sol2;
    bool result3 = sol2.isValid(s1);
    std::cout << "result:" << result3 << std::endl;

    return 0;
}   

#endif