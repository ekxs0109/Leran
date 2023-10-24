// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem748.h"

#include <unordered_map>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// 先计算词频率，再匹配出符合的单词
// 时间复杂度：O(n*m) n为words的长度，m为licensePlate的长度
// 空间复杂度：O(m)

// @lc code=start
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        unordered_map<char, int> pool;

        for (auto ch : licensePlate)
        {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                char lowerCh = tolower(ch);
                pool[lowerCh]++;
            }
        }
        string res;

        for (auto word : words)
        {
            unordered_map<char, int> wordPool;

            for (auto ch : word)
            {
                char lowerCh = tolower(ch);
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') && pool.count(lowerCh)!=0)
                {
                    wordPool[lowerCh]++;
                }
            }

            bool flag = false;
            for(auto item : pool){
                if(wordPool.count(item.first)==0 || wordPool[item.first] <item.second ){
                    flag = true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            if(res.empty() || res.size()>word.size()){
                res=word;
            }
        }

        return res;
    }
};
// @lc code=end
