44. Wildcard Matching (HARD)
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

class Solution {
public:
    //Method 1: use check point
    bool isMatch(string s, string p) {
        if(p == "*") return true;
        int si = 0, pi = 0, si_checkpoint, pi_checkpoint = 0;
        bool bHasCheckPoint = false;
        while(si < s.length()){
            if(s[si] == p[pi] || p[pi] == '?') {
                si++; pi++;
            }else if (p[pi] == '*'){ //save a check point here
                si_checkpoint = si;
                pi_checkpoint = pi++;
                bHasCheckPoint = true;
            }
            else if(bHasCheckPoint){ si = (si_checkpoint++)+1; pi = pi_checkpoint+1;}
            else return false;
        }
        while (pi < p.length() && p[pi] == '*'){pi++;}  
        return pi == p.length();  
    }

    //Method 2: Bruite force
    //Analyze: if consider char, s=p to ensure match
    //if there is '?', similar to above, but loose match
    //if there is p=*, always return true
    //-----------------------------------------------------
    //if there is * as prefix of p, the suffix of p need match
    //if there is * as suffix of p, the preffix of p need match
    //if there is * in between, suf/pre of p need match
    //but what about multiple * in a string?
    //use recursive, when encounter a *, consider one or more char are matched
    //to illustrate the recursive algorithm, can draw a divergence picture
    //942/1811 test cases: Time Limit Exceeded
    //--------------------------------------------------
    //Optimization: remove "***..." 1707 / 1811 test cass: Time Limit Exceeded
    bool isMatch(string s, string p) {
        if(p == "*") return true;
        return isMatchRecursive(s, p, 0, 0);
    }
    
    bool isMatchRecursive(string s, string p, int si, int pi){
        if(si==s.length() && pi == p.length()) return true;
        if(si == s.length()){
            for(int i = pi; i < p.length(); i++)
                if(p[i] != '*') return false;
            return true;
        }
            
        int si_checkpoint = 0;
        int pi_checkpoint = 0;
        if(s[si] == p[pi] || p[pi] == '?') {
            if(isMatchRecursive(s, p, si+1, pi+1)) return true;
        }else if (p[pi] == '*'){
            for(int i = si; i < s.length(); i++){
                int count = 1; //optimization: to remove case like "***...", jump to the next non-'*' char
                while(p[pi+count] == '*') count++; 
                if((pi+count) == p.length()) return true;
                si_checkpoint = i;
                pi_checkpoint = pi+count-1;
                if(isMatchRecursive(s, p, i, pi+count)) return true;
            }
        }
        
        if(pi_checkpoint) return isMatchRecursive(s, p, si_checkpoint+1, pi_checkpoint+1);
        return false;
    }
};
