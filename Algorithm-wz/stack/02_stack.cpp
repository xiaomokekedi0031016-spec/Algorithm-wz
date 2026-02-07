#include <stack>
#include <vector>
#include <iostream>

//    有N条鱼每条鱼的位置及大小均不同，他们沿着X轴游动，有的向左，有的向右。游动的速度是一样的，两条鱼相遇大鱼会吃掉小鱼。从左到右给出每条鱼的大小和游动的方向（0表示向左，1表示向右）。问足够长的时间之后，能剩下多少条鱼？   

class Solution {
public:
	//Size表示鱼的大小,Dir表示鱼的游动方向(0表示向左，1表示向右)
	int solution(std::vector<int>& Size, std::vector<int>& Dir) {
		if(Size.size() <= 1) {
			return Size.size();
		}
		int left = 0;
		int right = 1;
		std::stack<int> stk;
		for (int i = 0; i < Size.size(); ++i) {
			int currentFishDir = Dir.at(i);
			int currentFishSize = Size.at(i);
			
			bool hasEat = false;

			while (!stk.empty() && Dir[stk.top()] == right && currentFishDir == left) {
				if (Size[stk.top()] > currentFishSize) {
					hasEat = true;
					break;
				}
				stk.pop();
			}
			if(!hasEat) {
				stk.push(i);
			}
		}
		return stk.size();
	}
};

int main02() {
	//Solution
	std::vector<int> Size = { 4,3,2,1,5 };
	std::vector<int> Dir = { 0,1,0,0,0 };
	Solution sol;
	int count = sol.solution(Size, Dir);
	std::cout << "剩下的鱼:" << count << std::endl;
	return 0;
}


