//3¡¢Container With Most Water
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
		int i = 0, j = heights.size() - 1;
		int maxArea = 0;
		while (i < j) {
			int sum = min(heights[i], heights[j]) * (j - i);
			maxArea = max(maxArea, sum);
			if (heights[i] < heights[j]) {
				i++;
			} else {
				j--;
			}
		}
		return maxArea;
    }
};

int main() {
	Solution s;
	vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int result = s.maxArea(heights);
	cout << result << endl;
	return 0;
}	
