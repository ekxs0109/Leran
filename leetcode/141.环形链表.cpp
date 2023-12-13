// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem141.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(head ==nullptr) return false;
        ListNode * slow =head;
        ListNode * fast =head->next;

        while(slow!= nullptr && fast!=nullptr && fast->next !=nullptr){
            if(slow == fast) return true;
            slow =slow->next;

            fast = fast->next->next;
        }

        return false;
    }
};
// @lc code=end

