/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// 动态规划，但是不用使递归，会超时

// TODO: 使用矩阵算法计算

// 时间复杂度：O(n)
// 空间复杂度：O(1)

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n < 3)
            return 1;
        int p = 0, q = 0, r = 1, s = 1;

        for (int i = 3; i <= n; i++)
        {
            p = q;
            q = r;
            r = s;
            s = p + q + r;
        }
        return s;
    }
};
// @lc code=end
