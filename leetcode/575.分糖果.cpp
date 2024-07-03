// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem575.h"

using namespace std;
// @before-stub-for-debug-end

#include <unordered_set>


/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;
        int max = candyType.size()>>1;
        for(auto candy :candyType){
            if(set.count(candy)) continue;
            set.insert(candy);

            if(set.size()==max) return max;
        }
        return set.size();
    }
};
// @lc code=end

