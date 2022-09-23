5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
  
  
class Solution {
public:
    //Method 1: slow but strait forward Runtime: 100ms
    string longestPalindrome(string s) {
        string t = "##"; //double '#' to avoid lower boundary overflow
        for(int i = 0; i < s.length(); i++) {
            t += s[i];
            t += "#"; //insert '#' to handle cases like "cbba"
        }

        int maxCenter = 0;
        int maxRadius = 0;
        vector<int> radius(t.length(), 1);
        for(int i = 2; i < t.length()-1; i++){
            //Expand Radius
            while(t[i+radius[i]] == t[i-radius[i]]) radius[i]++; 
            //Update Global Info
            if(radius[i] > maxRadius){
                maxCenter = i;
                maxRadius = radius[i];               
            }
        }

        //Remove '#'
        string tmpString = t.substr(maxCenter-maxRadius+1, maxRadius*2-1);
        string resultString;
        for(int i = 0; i < tmpString.length(); i++)
            if(tmpString[i]!='#') resultString+=tmpString[i];
        return resultString;
    }
    
    //Method 2: use aux varaible to run faster, Runtime: 15ms
    string longestPalindrome(string s) {
        string t = "##"; //double '#' to avoid lower boundary overflow
        for(int i = 0; i < s.length(); i++) {
            t += s[i];
            t += "#"; //insert '#' to handle cases like "cbba"
        }
        
        int localMaxCenter = 0; //局部最大半径的中心
        int rightMost = 0;//这个并不表示局部最大半径，只是表示局部最大半径的最右端
        int maxCenter = 0;
        int maxRadius = 0;
        vector<int> radius(t.length(), 1);
        for(int i = 2; i < t.length()-1; i++){
            //Update radius with local info
            if(rightMost > i)   radius[i] = min(radius[2*localMaxCenter-i], rightMost-i);
            
            //Expand Radius
            while(t[i+radius[i]] == t[i-radius[i]]) radius[i]++;
            
            //Update Local Info
            if(rightMost < i+radius[i]){//更新局部最大半径和中心
                rightMost = i+radius[i];
                localMaxCenter = i;
            }
            
            //Update Global Info
            if(radius[i] > maxRadius){
                maxCenter = i;
                maxRadius = radius[i];               
            }
        }

        //Remove '#'
        string tmpString = t.substr(maxCenter-maxRadius+1, maxRadius*2-1);
        string resultString;
        for(int i = 0; i < tmpString.length(); i++)
            if(tmpString[i]!='#') resultString+=tmpString[i];
        return resultString;
    }

    
    //Method 3: an inovative way to calculate the final string. Runtime: 10ms
    string longestPalindrome(string s) {
        string t = "##";
        for(int i = 0; i < s.length(); i++){
            t += s[i];
            t += "#";
        }
        
        int localMaxCenter = 0; //局部最大半径的中心
        int rightMost = 0;//这个并不表示局部最大半径，只是表示局部最大半径的最右端
        int maxCenter = 0;
        int maxRadius = 0;
        vector<int> radius(t.length(), 1);
        for(int i = 2; i < t.length()-1; i++){
            if(rightMost > i)   radius[i] = min(radius[2*localMaxCenter-i], rightMost-i);
            
            //Expand Radius
            while(t[i+radius[i]] == t[i-radius[i]]) radius[i]++;
            
            //Update Local Info
            if(rightMost < i+radius[i]){//更新局部最大半径和中心
                rightMost = i+radius[i];
                localMaxCenter = i;
            }
            
            //Update Global Info
            if(radius[i] > maxRadius){
                maxCenter = i;
                maxRadius = radius[i];               
            }
        }

        return s.substr((maxCenter-maxRadius)/2, maxRadius-1);
    }

};
  
  
