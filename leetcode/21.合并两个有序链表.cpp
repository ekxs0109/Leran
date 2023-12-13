// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem21.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(list1+list2)
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root= new ListNode(0);
        ListNode* point=root;
        while(list1!=nullptr || list2!=nullptr){
            if(list1 ==nullptr){
                point->next = list2;
                list2 = list2->next;
            }else if(list2 ==nullptr){
                point->next = list1;
                list1 = list1->next;
            }else{
                bool flag = list1->val<list2->val;
                if(flag){
                    point->next = list1;
                    list1 = list1->next;
                }else{
                    point->next =  list2;
                    list2 = list2->next;
                }
            }
            point = point->next;
        }
        return root->next;
    }
};
// @lc code=end

