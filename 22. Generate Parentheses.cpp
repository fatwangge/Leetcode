22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
  
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string oneRes;
        recursive(res, oneRes, n, 0, 0);
        return res;
    }
    void recursive(vector<string> &res, string oneRes, int n, int l, int r){
        if(n == l){
            for(int i = 0; i < n-r; i++) oneRes += ')';
            res.push_back(oneRes);
        }else{
            recursive(res, oneRes + '(', n, l+1, r);
            if(l > r) recursive(res, oneRes + ')', n, l, r+1);
        }
    }
};
