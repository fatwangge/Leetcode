67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
  
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int length = max(a.length(), b.length());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        short carry = 0;
        for(int i = 0; i < length; i++){
            short x = i >= a.length() ? 0 : a[i] - '0';
            short y = i >= b.length() ? 0 : b[i] - '0';
            short z = x + y + carry;
            if(z > 1) {
                z -= 2;
                carry = 1;
            }else carry = 0;
            res = (char)('0'+z) + res;
        }
        if(carry) res = '1' + res;
        
        return res;
    }
};
