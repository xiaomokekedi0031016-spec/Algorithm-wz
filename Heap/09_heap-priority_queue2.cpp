#include <queue>
using namespace std;

class MedianFinder {
private:
	//大根堆，存储较小的一半元素
    priority_queue<int, vector<int>, less<int>> maxHeap;
	//小根堆，存储较大的一半元素
	priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {

    }

    void addNum(int num) {
		maxHeap.push(num);//一开始先把元素加入大根堆
		//保证大根堆中的最大值不大于小根堆中的最小值
        if (!minHeap.empty() && maxHeap.size() && maxHeap.top() > minHeap.top()) {
			minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
		//保持两个堆的大小平衡，允许一个堆比另一个堆多一个元素
        if (maxHeap.size() > minHeap.size()) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size()) {
			maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
		//小根堆中的数量多，说明总数为奇数，中位数是小根堆的堆顶
        if (minHeap.size() > maxHeap.size()) {
			return minHeap.top();
        }
        //大根堆中的数量多，说明总数为奇数，中位数是大根堆的堆顶
        else if (maxHeap.size() > minHeap.size()) {
			return maxHeap.top();
		}
        else {
            //两个堆的数量相等，说明总数为偶数，中位数是两个堆顶的平均值
			return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};
