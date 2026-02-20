#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int left = 0;
		int m = matrix.size();
		int n = matrix[0].size();
        int right = m * n - 1;//11
        while (left <= right) {
			int mid = left + (right - left) / 2;    
            int mid_value = matrix[mid / n][mid % n];
            if(mid_value == target) {
                return true;
            }
			else if (mid_value < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
		return false;
    }
};

int main14()
{
    vector<vector<int>> matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
	//cout << matrix.size() << endl;
	//cout << matrix[0].size() << endl;
    int target = 4;
    Solution sol;
    bool ans = sol.searchMatrix(matrix, target);
    cout << ans << endl;

    return 0;
}