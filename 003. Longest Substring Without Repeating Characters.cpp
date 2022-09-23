3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
  
两种解法：
1、使用hash set
2、使用辅助数组
  
class Solution {
public:
    //Method1: use unordered_set (unordered_set和unordered_map底层都是由哈希表实现的)
    //pseudo code
    //start to process s[end]
    //if s[end] not in umap, insert s[end] to uset;
    //if s[end] in umap, a loop to start++, erase s[start] from uset until s[start]==s[end]
    //end++;
    //example: "abcabcbb"
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int curLen = 0;
        unordered_set<char> uset;
        int start = 0, end = 0;
        
        while(end < s.length()){
            if(uset.find(s[end]) == uset.end()){
                uset.insert(s[end]); 
            }else{
                while(s[start] != s[end]){
                    uset.erase(s[start]);
                    start++; curLen--;
                }
                start++; curLen--;
            }
            
            end++;curLen++;
            maxLen = max(maxLen, curLen);
        }
        
        return maxLen;
    }
    
    //Method2: use aux array
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int result = 0;
        bool exist[256] = { false };
        while(j < s.length()) {
            if(exist[s[j]]){
                result = max(result, j - i);
                while(s[i] != s[j]){
                    exist[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            }else{
                exist[s[j]] = true;
                j++;
            }
        }
        result = max(result, (int)s.length() - i);
        return result;
    }

};
