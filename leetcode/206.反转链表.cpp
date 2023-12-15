// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem206.h"

using namespace std;
// @before-stub-for-debug-end


// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode =nullptr,* nextNode =nullptr;

        while(head!=nullptr){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};
// @lc code=end

