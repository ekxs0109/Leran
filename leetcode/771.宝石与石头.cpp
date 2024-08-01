// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem771.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;
        for(auto ch:jewels){
            set.insert(ch);
        }

        int ans = 0;

        for(auto ch: stones){
            if(set.count(ch)){
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end

