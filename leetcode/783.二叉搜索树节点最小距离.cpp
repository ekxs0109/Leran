// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem783.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
private:
    vector<int> vec;

public:
    void depth(TreeNode* root){
        if(!root){
            return;
        }
        vec.push_back(root->val);
        depth(root->left); 
        depth(root->right);

    }
    int minDiffInBST(TreeNode* root) {
        depth(root);
        int minNum = INT32_MAX;
        sort(vec.begin(),vec.end());
        int len = vec.size();
        for(int i = 1;i<len;i++){
            minNum = min(minNum, abs(vec[i-1]- vec[i]));
        }

        return minNum;
    }
};
// @lc code=end

