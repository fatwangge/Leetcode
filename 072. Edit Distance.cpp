72. Edit Distance (HARD)
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
  
class Solution {
public:
    //Analyze: DP
    //Example: horse, ros
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1
    //o 2 
    //s 3
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1 1             compare h and r, h!=r, min(2,2,0+1)
    //o 2 
    //s 3  
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1 1 2           compare ho and r, o!=r, min(2,3,1+1)
    //o 2 
    //s 3 
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1 1 2 2         compare hor and r, r==r, min(3,4,2+0)
    //o 2 
    //s 3     
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1 1 2 2 3       compare hors and r, s!=r, min(3,5,3+1)
    //o 2 
    //s 3         
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1 1 2 2 3 4     compare horse and r, e!=r, min(4,6,4+1)
    //o 2 
    //s 3    
    //    h o r s e
    //  0 1 2 3 4 5 
    //r 1 1 2 2 3 4    
    //o 2 2 1 2 3 4
    //s 3 3 4 5 2 3             
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.length()+1, vector<int>(word1.length()+1, 0));
        for(int i = 0; i < word2.length()+1; i++) dp[i][0] = i;
        for(int j = 0; j < word1.length()+1; j++) dp[0][j] = j;
        for(int i = 1; i < word2.length()+1; i++)
            for(int j = 1; j < word1.length()+1; j++)
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1] + (word1[j-1] == word2[i-1] ? 0 : 1));
        return dp[word2.length()][word1.length()];
    }
};
