// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem257.h"
#include <stack>

using namespace std;
// @before-stub-for-debug-end




/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> backtrace(TreeNode* node, string path){
        vector<string> res;
        string newPath = path.size() ==0 ? to_string(node->val) : (path+"->" + to_string(node->val));
        if(node->left !=nullptr){
            auto leftRes = backtrace(node->left, newPath);
            res.insert(res.end(), leftRes.begin(),leftRes.end());
        }
        if(node->right !=nullptr){
            auto rightRes = backtrace(node->right, newPath);
            res.insert(res.end(), rightRes.begin(),rightRes.end());
        }
        if(node->left ==nullptr && node->right ==nullptr){
            res.push_back(newPath);
        }
        return res;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        return backtrace(root, "");
    }
};
// @lc code=end

