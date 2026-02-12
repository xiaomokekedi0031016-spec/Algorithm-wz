/*
	求一组数的最小序列 >> 从左往右找最小的数且要满足一定条件
	保证前面的数尽量小，但还要保证后面还能凑够 k 个数
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> findSmallSeq(const vector<int>& nums, int k){
		if (nums.empty()) {
			return {};
		}
		vector<int> ans(k);//初始化vector大小为k,值为0
		stack<int> s;
		for (int i = 0; i < nums.size(); ++i) {
			const int x = nums[i];
			//提取k个数，所以要保留k个数
			//left表示还剩多少个数没有处理
			const int left = nums.size() - i;
			while (!s.empty() && ((int)s.size()) + left > k && s.top() > x) {
				s.pop();
			}
			s.push(x);
		}
		while ((int)s.size() > k) {
			s.pop();
		}
		// 把k个元素取出来，注意这里取的顺序!
		for (int i = k - 1; i >= 0; i--) {
			ans[i] = s.top();
			s.pop();
		}

		return ans;
	}
};


int main04() {
	//Solution
	Solution sol;
	vector<int> A = sol.findSmallSeq({ 3,5,2,6 }, 2);
	cout << "{";
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i];
		if (i != A.size() - 1)
			cout << ",";
	}
	cout << "}";

	//vector<int> v(3);
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	return 0;
}