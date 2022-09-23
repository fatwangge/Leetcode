28. Implement strStr()
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
  
  
class Solution {
public:
    //Method 1: simple
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        for(int i = 0; i < haystack.length(); i++){
            int j = 0;
            while(needle[j] == haystack[i+j]){
                j++;
                if(j == needle.length()) return i;//return the first occurance
            }
        } 
        return -1;
    }
    
    //Method 2: use KMP to improve performance
    /*
    char *strStr(char *haystack, char *needle) {
        if((*needle) == '\0') return haystack;
        
        char *hayLoop = haystack;
        int needleLength = strlen(needle);
        int index = 0, inc = 1;
        
        while(*(hayLoop + needleLength - 1) != '\0'){
            if(hayLoop[index] == needle[index]){
                index++;
                //Add this only to improve performance, refer KMP algorithm
                if(hayLoop[index] == needle[0] && inc==1)  inc = index - 1;
            }else{
                hayLoop += (inc==0?1:inc);
                index = 0;
                inc = 1;
            }
            if(index == needleLength) return hayLoop;
        }
        return NULL;
    }*/
};
