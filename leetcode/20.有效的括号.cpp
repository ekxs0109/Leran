// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

// "([]({}))"

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char,char> dict = {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        stack<char> st;
        for(auto ch: s){
            if(!dict[ch]){
                if(st.empty()) return false;
                if(st.top() != ch) return false;
                st.pop();
            }else{
                st.push(dict[ch]);
            }
        }
        return st.empty();
    }
};
// @lc code=end
