// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end


// 双指针遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* last = head;
        ListNode* point = head;

        while(point!=nullptr){
            if(last->val == val){
                head = head->next;
                last = head;
                point = head;
            }else if(point->val != val){
                last = point;
                point = point->next;
            }else{
                last->next = point->next;
                point = point->next;
            }
        }
        return head;
    }
};
// @lc code=end

