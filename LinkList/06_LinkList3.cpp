#if 0 

#include "06_LinkList.h"

//3、Linked List Cycle Detection
//链表环检测
//题目描述：给你一个链表的头节点 head ，判断链表中是否有环。如果链表中存在环，则返回 true 。 否则，返回 false 。
//示例 1：
//输入：head = [1,2,3,4], pos = 1
//			      ^    ^
//				  |	   |
//			       ----
//输出：true

//快慢指针法：使用两个指针，一个快指针每次移动两步，一个慢指针每次移动一步，如果链表中存在环，快指针最终会追上慢指针；如果链表中不存在环，快指针会先到达链表末尾。
class Solution {
public:
    bool hasCycle(ListNode* head) {
		ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
			slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; 
            }
        }
		return false; 
    }
};

int main() {
    // 创建链表节点
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    // 连接链表 1->2->3->4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // 手动制造环，4->2
    node4->next = node2;

    Solution sol;
    bool result = sol.hasCycle(node1);

    if (result)
        cout << "链表有环" << endl;
    else
        cout << "链表无环" << endl;

    return 0;
}
#endif