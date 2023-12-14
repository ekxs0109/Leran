// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

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
    ListNode *reverse(ListNode *root){
        ListNode * prev = nullptr;
        ListNode * next;
        while(root!=nullptr){
            next = root->next;
            root->next =prev;
            prev = root;
            root = next;
        }
        return prev;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        headA= reverse(headA);
        headB= reverse(headB); 

        while(headA != nullptr && headB !=nullptr){
            if(headA->val == headB->val){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end

