43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 
Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

class Solution {
public:
    //Analyze: becaues length of num1/num2 is too large, can not use stoi/itos
    //ex: 16*34 = 6*4 + 6*30 + 10*4 + 10*30
    //"0000"     "0024""0180" "0040" "0300" = "0544"
    //Pos        0+0    0+1    1+0   1+1
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < num1.size(); i++){
            short digit1 = num1[i]-'0'; //6; 1
            short carry = 0;
            for(int j = 0; j < num2.size(); j++){
                short digit2 = num2[j] - '0';   //4; 3; 4; 3
                short dig_mul = res[i+j] - '0' + digit1 * digit2 + carry;    //24; 18+2=20; 4; 2+3
                res[i+j] = '0' + dig_mul%10;    //res[0+0]=24%10=4; res[0+1]=20%10=0; res[1+0]=4; res[1+1]=5
                carry = dig_mul/10; //2; 2; 0; 0
            }
            if(carry > 0) res[i+num2.size()] = '0' + carry;//res[0+2]=2; res[1+2]=0
        }
        
        reverse(res.begin(), res.end());
        int start = 0;
        while(res[start] == '0'){start++;}
        if(start == res.size()) return "0";
        return res.substr(start, res.size()-start);
    }
};
