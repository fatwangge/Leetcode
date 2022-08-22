10. Regular Expression Matching (HARD)
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
   
  
class Solution {
public:   
    //Test case: s="aab", p="c*a*b", true. Explain: p="[c*][a*]b"
    //Test case: s="ab", p=".*c", false . Explain: p="[.*]c"  
    
    //Algorithm: each time read a char, also read the following char in pattern
    //if the following is *, initiate special compare, otherwise normal compare
    bool isMatch(string s, string p) {
        return isMatchRecursive(s, 0, p, 0);
    }
    
    bool isMatchRecursive(string s, int si, string p, int pi){
        if(pi == p.length()) return si == s.length();

        if(p[pi+1] != '*'){
            if(match(s[si], p[pi]) && si < s.length()) return isMatchRecursive(s, si+1, p, pi+1);
            else return false;
        }else{
            while(match(s[si], p[pi]) && si < s.length()){ //!here use loop instead of another recursive
                if(isMatchRecursive(s, si, p, pi+2)) return true; //*=0
                si++;
            }
            return isMatchRecursive(s, si, p, pi+2);
        }
        
        return false;
    }
    
    bool match(char sc, char pc){
        return pc == '.' || sc == pc;
    }
};



