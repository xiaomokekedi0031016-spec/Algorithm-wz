#if 0 

#include "06_LinkList.h"

//5、Remove Node From End of Linked List
//删除倒数第k个节点
//题目描述：给你一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//示例 1：
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0, head);
		ListNode* slow = dummy;
		ListNode* fast = dummy->next;
		while (n--) {
			fast = fast->next;
		}
		while (fast) {
			slow = slow->next;
			fast = fast->next;
		}
		//slow指向要删除节点的前一个节点
		slow->next = slow->next->next;
		return dummy->next;
    }
};

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = 2; // 删除倒数第 n 个节点

	ListNode* head = createList(arr, 5);
	cout << "原链表: ";
	printList(head);

	Solution sol;
	head = sol.removeNthFromEnd(head, n);

	cout << "删除倒数第 " << n << " 个节点后: ";
	printList(head);

	return 0;
}


#endif
