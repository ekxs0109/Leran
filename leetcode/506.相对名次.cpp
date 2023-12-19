// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem506.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<pair<int, int>> arr;

        int i = 0;
        for (auto item : score)
        {
            arr.emplace_back(make_pair(-item, i++));
        }

        sort(arr.begin(), arr.end());

        i = 0;
        vector<string> res(score.size());
        for (auto it : arr)
        {
            switch (i++)
            {
            case 0:
                res[it.second] = "Gold Medal";
                break;
            case 1:
                res[it.second] = "Silver Medal";
                break;
            case 2:
                res[it.second] = "Bronze Medal";
                break;
            default:
                res[it.second] = to_string(i);
                break;
            }
        }
        return res;
    }
};
// @lc code=end
