#if 0 
//6¡¢Encode and Decode Strings
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (auto& str : strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            j += 1;
            i = j;
            j += length;
            result.push_back(s.substr(i, length));
            i = j;
        }
        return result;
    }
};

int main() {
    Solution solution;

    // ²âÊÔÊý¾Ý
    vector<string> strs = { "hello", "world", "C++", "123" };

    // ±àÂë
    string encoded = solution.encode(strs);
    cout << "Encoded string: " << encoded << endl;

    // ½âÂë
    vector<string> decoded = solution.decode(encoded);
    cout << "Decoded strings:" << endl;
    for (auto& str : decoded) {
        cout << str << endl;
    }

    return 0;
}

#endif