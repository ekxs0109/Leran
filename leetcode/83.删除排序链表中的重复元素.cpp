// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem83.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto point = head;
        while(point && point->next){
            if(point->val == point->next->val){
                point->next = point->next->next;
            }else{
                point = point->next;
            }
        }
        return head;
    }
};
// @lc code=end

