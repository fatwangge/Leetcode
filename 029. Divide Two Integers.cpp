29. Divide Two Integers
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
  
  
class Solution {
public:
    //Goal: divide two integers without using *, /, and % operator
    //Analyze: intuitive method is to use - to substract divisor each iteration, but it caused too much time
    //A better method is to use greedy algorithm
    //Ex: dividend = 100, divisor = 3, instead of try 
    //100-3, result = 1
    //97-3, result = 2
    //94-3, result = 3
    //...
    //4-3, result = 33
    //Use a double loop iteration method(Greedy):
    //100-3, count = 1, result = 2^0 = 1
    //97-6, count = 2, result = 1 + 2^1 = 1+2 = 3
    //91-12, count = 3, result = 1 + 2^1 + 2^2 = 1+2+4 = 7
    //79-24, count = 4, result = 1 + 2^1 + 2^2 + 2^3 = 1+2+4+8=15
    //55-48, count = 5, result = 1 + 2^1 + 2^2 + 2^3 + 2^4 = 1+2+4+8+16=31
    //now 48*2 > 7, reset in the next outer loop
    //7-3, count = 1, result = 31 + 2^0 = 32
    //now 3*2 > 4, reset in the next outer loop
    //4-3, count = 1, result = 32 + 2^0 = 33
    //Extra Challenge: 32-bit environment (can't use 64-bits long long type)
    int divide(int dividend, int divisor) {
        //Special handling sign and INT_MIN
        if(divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
        if(dividend == INT_MIN){
            if(divisor == -1) return INT_MAX;
            return divisor > 0 ? divide(dividend+divisor, divisor)-1 : divide(dividend-divisor, divisor)+1;
        }
        signed char dividendSign = 1, divisorSign = 1;
        if(dividend < 0) dividendSign = -1;
        if(divisor < 0) divisorSign = -1;
        dividend= abs(dividend); //2147483648
        divisor = abs(divisor); //1

        //Test case: -214748648(-2^31), 1. output: 2147483647(2^31-1)
        int result = 0;
        while (dividend >= divisor) {
            int count = 0;
            for (int i = divisor; i <= dividend; i *= 2) {//i = 1, 2, 4, 8, 16,...
                dividend -= i;//dividend -= 1, 2, 4, 8, 16...
                result += pow(2, count++);//Alternative to power: 1 << count //result = 2^1 + 2^2 + 2^3,...
                if(i > INT_MAX/2) break; //to avoid i*2 exceed 2^31-1
            }
        }

        return result * dividendSign * divisorSign;;

    }
};
