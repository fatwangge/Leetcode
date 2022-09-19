65. Valid Number
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false
 
Constraints:

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
  
class Solution {
public:
    //.e1 => false
    //46.e3 => true
    //precede of 'e' should be either a number or a number and a point
    //an interger should follow 'e'
    bool isNumber(string s) {
        bool isBegin = true; //at the beginning of a digit, can be '+' or '-', otherwise not allowed
        bool canEnd = false; //the end of a number should be a digit, or a digit and '.'
        bool hasE = false; // A valid number should not have 2 Es
        bool hasDot = false; // A valid number should have 1 dot. or If there is 'e', reset this
        bool isDigit = false; //to check if the previous content is a valid number or not
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+' && !isBegin) return false;
            if(s[i] == '-' && !isBegin) return false;
            
            if(s[i] == 'e' || s[i] == 'E'){
                if(isBegin) return false;
                if(hasE) return false;
                else hasE = true;
                if(!isDigit) return false;
                hasDot = true;
                canEnd = false;
            }
            
            if(s[i] == '.'){
                if(hasDot) return false;
                else hasDot = true;   
                if(isDigit) canEnd = true;
                else canEnd = false;
            }
            
            if(s[i] >= '0' && s[i] <= '9') {
                canEnd = true;
                isDigit = true;
            }else{
                if(s[i] != '+' && s[i] != '-' && s[i] != '.' && s[i] != 'e' && s[i] != 'E') return false;    
                if(isDigit && s[i] == '.') isDigit = true;
                else isDigit = false;
            } 

            if(s[i] == 'e' || s[i] == 'E')isBegin = true;
            else isBegin = false;
        }
        
        return canEnd;
    }
};

  
