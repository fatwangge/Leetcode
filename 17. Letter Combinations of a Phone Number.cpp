17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
  
class Solution {
public:
    //Analyze: because the length of digits is not fixed, can not determine how many loops we need. So use recursive method
    const vector<string> data = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return vector<string>{};
        vector<string> res;
        string oneRes;
        FindCombinationRecursive(digits, res, oneRes, 0);
        return res;
    }
    
    void FindCombinationRecursive(string digits, vector<string> &res, string oneRes, int idx){
        if(idx >= digits.length()) res.push_back(oneRes);
        else for(int i = 0; i < data[digits[idx]-'2'].length(); i++)
            FindCombinationRecursive(digits, res, oneRes + data[digits[idx]-'2'][i], idx+1);
    }
};
