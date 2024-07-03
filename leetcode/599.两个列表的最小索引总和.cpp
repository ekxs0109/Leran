// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem599.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;

        int16_t curMin = INT16_MAX;
        vector<string> res;

        for(int i =0; i < list1.size() ; i++){
            map[list1[i]] = i;
        }
        for(int i =0; i < list2.size() ; i++){
            if(map.count(list2[i])){
                auto item = map[list2[i]];
                if((item + i) < curMin){
                    curMin = item + i;
                    res.clear();
                    res.push_back(list2[i]);
                }else if((item + i) == curMin){
                    res.push_back(list2[i]);
                }
            }
            
        }
        return res;
    }
};
// @lc code=end

