12. Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999



class Solution {
public:
    //Method 1: write a function to convert one digit
    string intToRoman(int num) {
        string res;
        int roundCounter = 0;
        while(num != 0){
            short digit = num % 10;
            num = num / 10;
            switch(roundCounter){
                case 0:
                    res = ConvertRomanDigit(digit, 'I', 'V', 'X') + res;
                    break;
                case 1:
                    res = ConvertRomanDigit(digit, 'X', 'L', 'C') + res;
                    break;    
                case 2:
                    res = ConvertRomanDigit(digit, 'C', 'D', 'M') + res;
                    break;   
                case 3:
                    res = ConvertRomanDigit(digit, 'M', '/', '/') + res;
                    break;                      
            }
            roundCounter++;
        }
        return res;
    }
    
    string ConvertRomanDigit(short digit, char I, char V, char X){
        string res;
        if(digit == 0) ;
        else if(digit == 1) res = res + I;
        else if(digit == 2) res = res + I + I;
        else if(digit == 3) res = res + I + I + I;
        else if(digit == 4) res = res + I + V;
        else if(digit == 5) res = res + V;
        else if(digit == 6) res = res + V + I;
        else if(digit == 7) res = res + V + I + I;
        else if(digit == 8) res = res + V + I + I + I;
        else if(digit == 9) res = res + I + X;
        
        return res;
    }
    
    
    
    //Method 2: First construct basic roman number, than combine
    string intToRoman(int num) {
        string Romans = "IVXLCDM";
        int RomanIntegers[7] = {1, 5, 10, 50, 100, 500, 1000};
        string result;
        
        //Compute Basic Roman
        for(int i = 6; i >= 0; i--){
            int n = num / RomanIntegers[i];
            for(int j = 0; j < n; j++) result += Romans[i];
            num = num % RomanIntegers[i];
        }
        
        //Combine all characters to higher level
        int l = result.size();
        char lastChar = '#';
        int charCount = 0;
        for(int i = 0; i < l; i++){
            if(result[i] == lastChar) charCount++;
            else charCount = 0;
            
            bool continueEnd = true;
            if(i <= (l-1) && result[i+1] == lastChar) continueEnd = false;
            
            if(continueEnd){
                if(charCount == 4){
                    result[i-4] = GetHigherLevel(lastChar);
                    result[i-3] = '#';
                    result[i-2] = '#';
                    result[i-1] = '#';
                result[i  ] = '#';
                }else if(charCount == 3){
                    if((i >= 4) && result[i-4] == GetHigherLevel(lastChar)){
                        result[i-4] = lastChar;
                        result[i-3] = GetHigherLevel(GetHigherLevel(lastChar));
                        result[i-2] = '#';

                    }else{
                        result[i-3] = lastChar;
                        result[i-2] = GetHigherLevel(lastChar);
                    }
                    result[i-1] = '#';
                    result[i  ] = '#';
                }
                charCount = 0;
            }
            
            lastChar = result[i];
        }
        
        //Remove # and return
        string finalResult;
        for(int i = 0; i < l; i++) if(result[i] != '#') finalResult += result[i];
        return finalResult;
    }
    
    char GetHigherLevel(char x){
        string Romans = "IVXLCDM";
        for(int i = 0; i < Romans.size()-1; i++) if(Romans[i] == x) return Romans[i+1];
        return '#';
    }

};

