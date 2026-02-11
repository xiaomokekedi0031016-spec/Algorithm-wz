/*
* 字符串解码
* 
示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
*/
#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack <int> nums;
        stack <string> strs;
        int num = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                res = res + s[i];//append
            }
            else if (s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
            {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; ++j)
                    strs.top() += res;
                res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                //若是左括号，res会被压入strs栈，作为上一层的运算
                strs.pop();
            }
        }
        return res;
    }
};

class Solution1 {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        string str = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                str.push_back(s[i]);//push_back(char)   >> +=
            }
            else if (s[i] == '[') {
                nums.push(num);
                strs.push(str);
                num = 0;
                str = "";
            }
            else {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; ++j) {
                    strs.top().append(str);//append(string) >> +=
                }
                str = strs.top();
                strs.pop();
            }
        }
        return str;
    }
};

int main06() {
	Solution sol;
	string s = "3[a2[c]]";
	string res = sol.decodeString(s);

	cout << "res: " << res << endl;	

	Solution1 sol1;
    string res1 = sol1.decodeString(s);

    cout << "res1: " << res1 << endl;


    return 0;
}