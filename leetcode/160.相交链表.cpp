// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

// m+n+m
// n+m+n
// 时间复杂度：O(m+n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode * nodeA = headA;
        ListNode * nodeB = headB;
        while(nodeA !=nodeB){
            nodeA = nodeA ==nullptr ? headB : nodeA->next; // 同时走，如果长度不一致 ，走完一圈后，就能过刨除两条链表长度的差距
            nodeB = nodeB ==nullptr ? headA : nodeB->next;
        }
        return nodeA;
    }
};
// @lc code=end

