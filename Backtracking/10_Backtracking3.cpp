#if 0

//3、电话号码的字母组合
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        string tmp;
        unordered_map<char, string> umap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        //dfs
        dfs(res, digits, 0, tmp, umap);
        return res;
    }
    //res保存结果，digits是输入的数字字符串，index是当前处理的数字下标，tmp是当前的字母组合(临时的结果)，u_map是数字到字母的映射
    void dfs(vector<string>& res, string& digits, int index, string& tmp, unordered_map<char, string>& umap) {
        if (index == digits.length()) {
            res.emplace_back(tmp);
            return;
        }
        for (auto c : umap[digits[index]]) {
            tmp.push_back(c);
            dfs(res, digits, index + 1, tmp, umap);
            tmp.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> res = sol.letterCombinations(digits);
    for (const auto& combination : res) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}
#endif
