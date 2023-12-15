// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem404.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        auto res = 0;
        stack<TreeNode*> stk;
        bool flag = true;

        while(root !=nullptr || !stk.empty()){
            while(root !=nullptr){
                stk.push(root);
                if(root->left == nullptr && root->right ==nullptr && !flag ){
                    res +=root->val;
                }
                root= root->left;
                flag =false;
            }
            auto node = stk.top();
            stk.pop();
            root = node->right;
            flag = true;
        }
        return res;
    }
};
// @lc code=end

