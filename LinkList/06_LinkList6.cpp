#if 0 
#include "06_LinkList.h"
#include <vector>
using namespace std;

//6、Merge K Sorted Linked Lists
//合并K个有序链表
//题目描述：给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，返回合并后的链表。
//示例 1：
//输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		if (lists.size() == 1) return lists[0];
		while (lists.size() > 1) {
			vector<ListNode*> mergedLists;
			for (int i = 0; i < lists.size(); i += 2) {
				ListNode* l1 = lists[i];
				ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
				mergedLists.push_back(mergeTwoLists(l1, l2));
			}
			lists = mergedLists;
		}
		return lists[0];
    }

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode dummy(0);
		ListNode* node = &dummy;
		while (list1 && list2) {
			if(list1->val < list2->val)
			{
				node->next = list1;
				node = node->next;
				list1 = list1->next;
			}
			else {
				node->next = list2;
				node = node->next;
				list2 = list2->next;
			}
		}
		if (list1) {
			node->next = list1;
		}
		if (list2)
		{
			node->next = list2;
		}
		return dummy.next;
	}
};

// main 函数
int main() {
	// 创建多个有序链表
	int arr1[] = { 1, 4, 5 };
	int arr2[] = { 1, 3, 4};
	int arr3[] = { 2, 6};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	ListNode* l1 = createList(arr1, n1);
	ListNode* l2 = createList(arr2, n2);
	ListNode* l3 = createList(arr3, n3);

	// 放入 vector
	vector<ListNode*> lists = { l1, l2, l3 };

	cout << "Lists before merging:" << endl;
	for (int i = 0; i < lists.size(); ++i) {
		cout << "List " << i + 1 << ": ";
		printList(lists[i]);
	}
	// 合并链表
	Solution sol;
	ListNode* merged = sol.mergeKLists(lists);

	// 输出结果
	cout << "Merged list: ";
	printList(merged);

	return 0;
}
#endif