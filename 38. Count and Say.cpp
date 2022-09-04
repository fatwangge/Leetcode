38. Count and Say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":

Given a positive integer n, return the nth term of the count-and-say sequence.

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 
Constraints:

1 <= n <= 30
  
class Solution {
public:
    //Method 1: Iteration, 100ms
    string countAndSay(int n) {
        string res = "1";
        for(int i = 0; i < n-1; i++)
            res = countLoop(res);
        return res;
    }
    
    string countLoop(string input_string){
        string res = "";
        for(int i = 0; i < input_string.length(); i++){
            int count = 1;
            while(i+1 < input_string.length() && input_string[i] == input_string[i+1]){
                i++;
                count++;
            }
            res = res + to_string(count) + input_string[i]; 
        }
        return res;        
    }
    
    //Method 2: Recursive, 100ms
    string countAndSay(int n) {
        string res = "";
        if(n == 1) {
            res = "1";
            return res;
        }
        string lastRes = countAndSay(n-1);
        for(int i = 0; i < lastRes.length(); i++){
            int count = 1;
            while(i+1 < lastRes.length() && lastRes[i] == lastRes[i+1]){
                i++;
                count++;
            }
            res = res + to_string(count) + lastRes[i]; 
        }
        return res;
    }
};
