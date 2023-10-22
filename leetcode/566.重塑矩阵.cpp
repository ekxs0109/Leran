// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem566.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// [[1,2],[3,4]], r = 2, c = 4
// i j
// 遍历mat
// 时间复杂度：O(row*col)
// 空间复杂度：O(1)
// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int i = 0, j = 0,row =mat[0].size() ,col=mat.size();

        if(row*col != r*c) return mat;


        vector<vector<int>> res(1,vector<int>());


        for (auto row : mat)
        {
            for (auto num : row)
            {
                if (!(j % c != 0 || j == 0))
                {
                    j = 0;
                    i++;
                    res.push_back(vector<int>());
                }

                res[i].push_back(num);
                j++;
            }
        }
        return res;
    }
};
// @lc code=end
