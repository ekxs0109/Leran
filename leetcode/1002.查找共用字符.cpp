// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>
#include "commoncppproblem1002.h"

using namespace std;
// @before-stub-for-debug-end


// 与官方的思路一样，只是内存vector的使用有些欠缺
// 时间复杂度：O(n(m+|Σ|)) n为words的长度， m为字符串集，|Σ|为遍历的字符集
// 空间复杂度：O(|Σ|)

/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26,INT_MAX);
        vector<int> freq(26);

        for(auto& word:words){
            fill(freq.begin(), freq.end(), 0);
            for(auto ch:word){
                freq[ch - 'a']++;
            }

            for(int i=0;i<26;i++){
                minFreq[i]= min(minFreq[i], freq[i]);
            }
        }

        vector<string> res;
        for(int i = 0;i< 26;i++){
            for(int j =0;j<minFreq[i];j++){
                res.emplace_back(1,i+'a'); // 直接传递构造参数，让vector内部创建，提升性能
            }
        }
        return res;
    }
    vector<string> commonCharsSelf(vector<string> &words)
    {
        unordered_map<char, int> firstMap;
        for (auto ch : words[0])
        {
            firstMap[ch]++;
        }

        int len = words.size();

        for (int i = 1; i < len; i++)
        {
            unordered_map<char, int> wordMap;
            for (auto ch : words[i])
            {
                wordMap[ch]++;
            }
            auto it = firstMap.begin();
            while(it!=firstMap.end()){
                if(wordMap[(*it).first] != (*it).second ){
                    (*it).second = min(wordMap[(*it).first],(*it).second );
                }
                it++;
            }
        }

        vector<string> res;
        for(auto item :firstMap){
            if(item.second>0){
                for(int i = 0; i<item.second;i++){
                    res.push_back(string(1, item.first));
                }
            }
        }

        return res;
    }
};
// @lc code=end
