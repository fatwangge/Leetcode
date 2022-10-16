89. Gray Code
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]

Constraints:

1 <= n <= 16
  

class Solution {
public:
    //Method 1:
    //规律：result 里面会有 2^n 个数。i从0~2^n，每次i与i>>1取XOR。相当于i跟它旁边的那一位取XOR
    //i=0: res.push_back((0/2)^0=0b000^0b000=0b000);
    //i=1: res.push_back((1/2)^1=0b000^0b001=0b001);
    //i=2: res.push_back((2/2)^2=0b001^0b010=0b011);
    //(3/2)^3                   =0b001^0b011=0b010
    //(4/2)^4                   =0b010^0b100=0b110
    //...
    vector<int> grayCode(int n) {   
      vector<int> ret;   
      int size = 1 << n;   
      for(int i = 0; i < size; ++i)   ret.push_back((i >> 1)^i);   //^ is XOR
      return ret;   
    }
    
    //Method 2:
    //规律: n=k时的Gray Code，相当于n=k-1时的Gray Code的逆序 加上 1<<k。
    //因此，每次iteration，都在新数据最高位置1，然后把之前已经有的序列反过来再加一遍
    //初始:         0000
    //i=0时候的序列：0000, 0001
    //i=1时候的序列：0000, 0001, 0011, 0010
    //i=2时候的序列：0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100
    //i=3时候的序列: 0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100, 1100, 1101, ...
    vector<int> grayCode(int n) {
        vector<int> result;      
        result.push_back(0);  
        for(int i = 0; i < n; i++) {  
            int highestBit = 1<<i;  
            int len = result.size();  
            for(int i = len-1; i>=0; i--)  
                result.push_back(highestBit + result[i]);  
        }  
        return result;  
    }
};
  
