76. Minimum Window Substring (HARD)
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
  
class Solution {
public:
    //Input: s = "ADOBECODEBANC", t = "ABC"
    //increase end to 5, "ADOBEC"                                         
    //increase start to 0, "DOBEC" (Save "ADOBEC")                           
    //increase end to 10, "DOBECODEBA"                                    
    //increase start to 5, "ODEBA" (Save "CODEBA")                           
    //increase end to 12, "CODEBANC"                                      
    //increase start to 9,"ANC" (Save "BANC") 
    //Meed to consider duplicate chars in the string: "aa", "aa"
    string minWindow(string s, string t) {
        if(t.length() == 0|| s.length() == 0) return "";
        
        //Use count1 as counter, use count2 as reference
        vector<int> count1, count2;
        
        for(int i  = 0; i < 256; i++){
            count1.push_back(0);
            count2.push_back(0);
        }
        for(int i  = 0; i < t.length(); i++){
            count1[t[i]]++;
            count2[t[i]]++;
        }
        
        //If count is zero, find a solution
        int count = t.length();
        
        int start = 0;
        int minSize = INT_MAX;
        int minStart;
        
        for(int end = 0; end < s.length(); end++){
            count1[s[end]]--;
            if(count1[s[end]] >= 0) count--;
        
            //Use every char as start, handle end situation
            if(count == 0){
                while(true){
                    if(count2[s[start]] > 0){//use count2 as reference
                        if(count1[s[start]] < 0) count1[s[start]]++;
                        else break;
                    }
                    start++;
                }

                if(minSize > (end - start + 1)){
                    minSize = end - start + 1;
                    minStart = start;
                }
            }
        }
        
        if(minSize == INT_MAX) return "";
        string res(s, minStart, minSize);
        return res;
    }
};
  
