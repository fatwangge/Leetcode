32. Longest Valid Parentheses (HARD)
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
  
class Solution {
public:
    //用DP法。dp[i]==j表示i到j节点能连接
    //初始化dp[i]=[i]，即每个节点都没有连接
    //遍历数组s[i]，如果是(什么也不处理
    //如果是)，以下三步：
    //Step1、找到匹配的(：这个可能是i左边的一位，也可能是左边的好几位，假设是j，就令dp[i] = j；或者它不存在，那就continue
    //Step2、找到j-1那一位：看看j-1有没有连别的点，有的话就两端连好，即令dp[i] = dp[j-1]
    //Step3、更新最大长度
    int longestValidParentheses(string s) {
        vector<int> dp;
        for(int i = 0; i < s.length(); i++) dp.push_back(i);
        int maxLen = 0;
        
        for(int i = 1; i < s.length(); i++){
            if(s[i] == '(') continue;
            
            //Step1
            int j = i - 1;
            if(s[j] == ')') j = dp[j]-1; 
            if(j >= 0 && s[j] == '(') dp[i] = j;
            else continue;   
            
            //Step2
            if(j > 0 && dp[j-1] != j - 1) dp[i] = dp[j-1];
            
            //Step3
            int currentLen = i-dp[i]+1;
            maxLen = currentLen > maxLen ? currentLen : maxLen;
        }
        
        return maxLen;
    }
};
