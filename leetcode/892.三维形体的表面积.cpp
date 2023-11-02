// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include "commoncppproblem892.h"

using namespace std;
// @before-stub-for-debug-end

// [[1,2],[3,4]]
// (bLen 2 * sLen 2 ) *2 + maxS 3+4  +maxB 2+4 = 34

// [[1,1,1],[1,0,1],[1,1,1]]
//  (8)*2 + 3*2+3*2  + 4

// 3 2 1 2  

// 时间复杂度：O(N^2)，其中 N 是 grid 中的行和列的数目
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0 ;
        for(int i =0; i< grid.size();i++){
            for(int j =0 ;j< grid[i].size();j++){
                int cur = grid[i][j];

                if(cur > 0){
                    result += (cur <<2) +2; //  左右前后四面 + 上下

                    // 减去与自己相邻的前后表面积
                    result -= i>0 ? min(cur, grid[i-1][j]) << 1: 0;

                    // 减去与自己相邻的左右表面积
                    result -= j>0 ? min(cur, grid[i][j-1]) << 1 : 0;
                }

            }
        }
        return result;
    }
};
// @lc code=end

