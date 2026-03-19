#if 0 
#include "06_LinkList.h"

//2、Merge Two Sorted Lists
//合并两个有序链表
//题目描述：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//示例 1：
//输入：list1 = [1,2,4], list2 = [1,3,4]
//输出：[1,1,2,3,4,4]

class Solution {
public:
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
        if (list2) {
            node->next = list2;
        }
		return dummy.next;
    }
};

int main() {
    // 示例数组，用于创建链表
    int arr1[] = { 1, 3, 5 };
    int arr2[] = { 2, 4, 6 };

    // 创建链表
    ListNode* list1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    ListNode* list2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    // 打印原始链表
    cout << "List1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);

    // 合并链表
    Solution solution;
    ListNode* merged = solution.mergeTwoLists(list1, list2);

    // 打印合并后的链表
    cout << "Merged List: ";
    printList(merged);

    // 释放链表内存
    ListNode* temp;
    while (merged) {
        temp = merged->next;
        delete merged;
        merged = temp;
    }

    return 0;
}
#endif