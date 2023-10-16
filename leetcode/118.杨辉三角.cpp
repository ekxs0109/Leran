// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem118.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
//          1          ----- 1
//         1 1         ----- 2
//        1 2 1        ----- 3
//       1 3 3 1       ----- 4
//      1 4 6 4 1      ----- 5
//     1 5 10 10 5 1    ---- 6
// 时间复杂度： O(numRows^2)
// 空间复杂度： O(numRows^2)

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i =0 ; i< numRows;i++){
            vector<int> layer;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    layer.push_back(1);
                }else{
                    layer.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(layer);
        }
        return res;

    }
};
// @lc code=end

