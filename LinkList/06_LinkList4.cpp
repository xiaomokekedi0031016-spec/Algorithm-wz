#if 0 

#include "06_LinkList.h"

//4、Reorder Linked List
//重排链表
//题目描述：给定一个单链表 L 的头节点 head ，单链表 L 表示为：L0 → L1 → … → Ln-1 → Ln 。请将其重新排列后变为：L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
//示例 1：
//输入：head = [1,2,3,4]
//输出：[1,4,2,3]

//先找到中心点，然后将后半部分链表反转，最后将前半部分和反转后的后半部分交叉合并。

class Solution {
public:
    void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return;
		ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
		}
        ListNode* second = slow->next;
		ListNode* prev = nullptr;
		slow->next = nullptr;
        while (second) {
			ListNode* temp = second->next;
			second->next = prev;
			prev = second;
			second = temp;
        }
		ListNode* first = head;
		second = prev;
		while (second) {
			ListNode* temp1 = first->next;
			ListNode* temp2 = second->next;
			first->next = second;
			second->next = temp1;
			first = temp1;
			second = temp2;
		}
    }
};

int main() {
	int arr[] = { 2, 4, 6, 8, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	ListNode* head = createList(arr, n);

	cout << "原始链表: ";
	printList(head);

	Solution sol;
	sol.reorderList(head);

	cout << "重排后链表: ";
	printList(head);

	return 0;
}

#endif