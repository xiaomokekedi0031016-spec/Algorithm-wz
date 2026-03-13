#if 0
//7、Product of Array Except Self
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n;++i) {
            //计算该索引左侧所有数的乘积
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = right * res[i];
            right = right * nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1,2,4,8 };
    Solution sol;

    vector<int> result(sol.productExceptSelf(nums));

    for (auto& res : result) {
        cout << res << " ";
    }


    return 0;
}

#endif