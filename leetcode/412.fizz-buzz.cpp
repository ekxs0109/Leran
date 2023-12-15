// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem412.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for(int i =1 ; i <= n; i++){
            string str;
            if(i%3 ==0){
                str+= "Fizz";
            }
            if(i%5 ==0){
                str+= "Buzz";
            }
            if(str.size()==0){
                str = to_string(i);
            }

            res.push_back(str);
        }

        return res;


    }
};
// @lc code=end

