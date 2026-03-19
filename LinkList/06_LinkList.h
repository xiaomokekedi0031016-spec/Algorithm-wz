#pragma once
#include <iostream>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;//节点存储的数据
    ListNode* next;//指向下一个节点的指针
    ListNode() : val(0), next(nullptr) {}//默认构造函数，初始化节点值为0，指针为nullptr
    ListNode(int x) : val(x), next(nullptr) {}//构造函数，初始化节点值为x，指针为nullptr
    ListNode(int x, ListNode* next) : val(x), next(next) {}//构造函数，初始化节点值为x，指针为next
};


// 辅助函数：打印链表
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

// 辅助函数：创建链表
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}