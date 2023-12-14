// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end


// 使用栈+prev记录路径 TODO: 复习
// 时间复杂度：O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> st;
        vector<int> res;

        TreeNode *prev = nullptr;

        while(root !=nullptr || !st.empty()){
            while(root !=nullptr){
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            if(root->right == nullptr || root->right == prev){
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }else{
                st.push(root);
                root = root->right;
            }
        }

        return res;
    }
};
// @lc code=end

