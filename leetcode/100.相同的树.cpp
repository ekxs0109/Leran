// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include "commoncppproblem100.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<TreeNode*> queP;
        queue<TreeNode*> queQ;

        if(!!p)queP.push(p);
        if(!!q)queQ.push(q);

        while(!queP.empty() && !queQ.empty()){
            TreeNode* nodeP= queP.front();
            TreeNode* nodeQ= queQ.front();
            queP.pop();
            queQ.pop();


            if( nodeP->val != nodeQ->val){
                return false;
            }
            if(!!nodeP->left != !!nodeQ->left){
                return false;
            }
            if(!!nodeP->right != !!nodeQ->right){
                return false;
            }
            if(nodeP->left)queP.push(nodeP->left);
            if(nodeQ->left)queQ.push(nodeQ->left);
            if(nodeP->right)queP.push(nodeP->right);
            if(nodeQ->right)queQ.push(nodeQ->right);
        }

        return queP.empty() ==queQ.empty();
    }
};
// @lc code=end

