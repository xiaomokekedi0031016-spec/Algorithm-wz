#if 0 
#include "06_LinkList.h"

//1、Reverse Linked List
//反转链表
//题目描述：给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//示例 1：
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]


// 反转链表的解法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
		ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
			prev = curr;
			curr = temp;
        }
		return prev;
    }
};


int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 创建链表
    ListNode* head = createList(arr, n);
    cout << "原链表: ";
    printList(head);
    // 反转链表
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    cout << "反转后链表: ";
    printList(reversedHead);

    return 0;
}
#endif
