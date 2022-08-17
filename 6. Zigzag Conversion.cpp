6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 
Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
  
  
class Solution {
public:
    //Method 1
    string convert(string s, int numRows) {
        string resultString;
        for(int i = 0; i < numRows; i++){
            bool downward = (i==numRows-1) ? false : true; //!
            
            int interval_up = (i == 0) ? 1 : i*2; //when numRow is 4: 1, 2, 4, 6
            int interval_down = (i == numRows-1) ? 1 : (numRows-1-i)*2;//when numRow is 4: 6, 4, 2, 1

            int currentIdx = i;
            if(currentIdx >= s.length()) break;//!
            
            do{
                resultString += s[currentIdx];
                currentIdx += downward ? interval_down : interval_up;
                if(i!=0 && i!=numRows-1) downward = !downward;//!
            }while(currentIdx < s.length());
        }
        
        return resultString;
    }
    
    //Method 2
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string result;
        if(s.size() ==0) return result;
        
        //Use math to compute index, indexRed = (n-1)*2*j+i, indexGreen = indexRed+2*(n-i-1)
        for(int i =0; i< nRows; i++)
            for(int j =0, indexRed = i; indexRed < s.size(); j++, indexRed = (nRows-1)*2*j+i){
                //Red Principal
                result.append(1, s[indexRed]);
                
                //Green Principal
                if(i ==0 || i == nRows-1) continue; 
                
                int indexGreen = indexRed + 2*(nRows - i - 1); //Times 2 to go a v shape to get green index
                if(indexGreen < s.size())  result.append(1, s[indexGreen]);
            }
        
        return result;
    }
};  
  
 
