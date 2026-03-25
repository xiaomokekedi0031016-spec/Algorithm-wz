//5、Car Fleet

#if 0 

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;//存储每辆车的位置和速度
        for (int i = 0; i < position.size(); ++i) {
            vec.emplace_back(position[i], speed[i]);
            //vec.push_back({ position[i],speed[i] });
            //vec.push_back(make_pair(position[i], speed[i]));
        }
        sort(vec.rbegin(), vec.rend());
        vector<double> result;
        for (auto& v : vec) {
            auto time = (double(target - v.first) / v.second);
            result.push_back(time);
            if (result.size() >= 2 && result.back() <= result[result.size() - 2]) {
                result.pop_back();
            }
        }
        return result.size();
    }
};


#endif
