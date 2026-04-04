#if 0 

//给定一个整数数组和一个整数k，返回数组中出现频率最高的k个元素
//5、Top K Frequent Elements

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

//排序解法:通过哈希表统计每个元素的频率，然后将频率和元素组成一个对，放入一个数组中，对这个数组进行排序，最后返回前k个元素
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;   
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> vec;
        for (const auto& t : freq) {
			vec.emplace_back(make_pair(t.second, t.first));//emplace_back不支持{}写法
        }
		sort(vec.rbegin(), vec.rend());
   //     sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
   //         return a.first > b.first;
			//});
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(vec[i].second);
        }
		return result;
    }
};

//最小堆pop和top都是最小的
//最小堆解法：通过哈希表统计每个元素的频率，然后使用一个最小堆来维护出现频率最高的k个元素。遍历哈希表中的每个元素，如果堆的大小小于k，则将当前元素加入堆中；如果堆的大小等于k，并且当前元素的频率大于堆顶元素的频率，则将堆顶元素弹出，并将当前元素加入堆中。最后，返回堆中的所有元素。
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
		//堆里存的数据类型是 pair<int, int>、底层用vector来存数据、使用greater比较器（而不是默认的 less）要的是类型不是可调用对象，所以直接写greater<pair<int,int>>，而不是greater<pair<int,int>>()
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> head;
        for (auto& t : freq) {
			head.push(make_pair(t.second, t.first));    
            if (head.size() > k) {
                head.pop();
			}
        }
		vector<int> result;
		//for (auto& t : head) { //error: priority_queue没有迭代器，无法使用范围for循环
        //    result.emplace_back(...)
        //}
  //      while (!head.empty()) {
  //          result.emplace_back(head.top().second);
  //          head.pop();
		//}
        for (int i = 0; i < k; i++) {
            result.push_back(head.top().second);
            head.pop();
        }
		return result;
    }
};
//桶排序思想：通过哈希表统计每个元素的频率，然后创建一个桶数组，桶的索引表示频率，桶中的元素表示具有该频率的数字。最后，从桶数组的末尾开始遍历，收集前k个元素。
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;   
        vector<vector<int>> vec(nums.size() + 1);
        for (auto& i : nums) {
            freq[i] += 1;
        }
        for (auto& t : freq) {
			vec[t.second].push_back(t.first);
        }
		vector<int> result;
        for (int i = vec.size() - 1; i >= 0; --i) {
            for (auto& s : vec[i]) {
                result.push_back(s);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    }
};

int main() {
    vector<int> nums = { 1, 1, 2, 2, 2, 3, 4, 4 ,4 };
    int k = 2;
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    Solution1 solution1;
    vector<int> result1 = solution1.topKFrequent(nums, k);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    Solution2 solution2;
    vector<int> result2 = solution2.topKFrequent(nums, k);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}


#endif