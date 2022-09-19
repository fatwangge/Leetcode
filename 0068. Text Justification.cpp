68. Text Justification (HARD)
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 
Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> r;

        string tmp = "";
        r.push_back(tmp);
        int lineCount = 0;
        int stringInLineCount = 0;
        int wordsInLineCount = 0;
        
        if(maxWidth == 0) return r;
        /*Even words = [""], it is still words.size() = 1*/
        if(words[0] == ""){
            r[0] = SettingSpace(r[0], 0, 0, maxWidth, false);
            return r;
        }
        
        for(int i = 0; i < words.size(); i++){
            stringInLineCount += words[i].length();
            if(stringInLineCount == maxWidth){
                /*Add word*/
                r[lineCount] += words[i];
                wordsInLineCount++;
                /*SettingSpace*/
                r[lineCount] = SettingSpace(r[lineCount], stringInLineCount, wordsInLineCount, maxWidth, false);
                /*Start a new line if this word is not the last word*/
                if(i != words.size()-1){
                    string tmp = "";
                    r.push_back(tmp);
                    stringInLineCount = 0;
                    wordsInLineCount = 0;
                    lineCount++;
                }
            }else if(stringInLineCount > maxWidth){
                /*Remove words*/
                stringInLineCount -= words[i].length();
                /*SettingSpace*/
                r[lineCount] = SettingSpace(r[lineCount], stringInLineCount, wordsInLineCount, maxWidth, false);
                /*Start a new line and Add word*/
                string tmp = words[i];
                r.push_back(tmp);
                stringInLineCount = words[i].length();
                wordsInLineCount = 1;
                lineCount++;
                /*After adding word, add a space, if there is word next*/
                if((i != words.size()-1) && (stringInLineCount < maxWidth)){
                    stringInLineCount++;
                    r[lineCount] += ' ';
                }
            }else{
                /*Add word*/
                r[lineCount] += words[i];
                wordsInLineCount++;
                /*After adding word, add a space, if there is word next*/
                if((i != words.size()-1) && (stringInLineCount < maxWidth)){
                    stringInLineCount++;
                    r[lineCount] += ' ';
                }
            }
        }
        
        /*Need setting space for the last line*/
        r[lineCount] = SettingSpace(r[lineCount], stringInLineCount, wordsInLineCount, maxWidth, true);
        
        return r;
    }
    
    string SettingSpace(string x, int stringInLineCount, int wordsInLineCount, int maxWidth, bool lastLine){
        int spaceCount = 0;
        int n = x.length();
        //if(x[n-1] == ' ') n--;
        for(int i = 0; i < n; i++) 
            if(x[i] == ' ') spaceCount++;
        spaceCount += (maxWidth - stringInLineCount);
        
        if(wordsInLineCount < 2 || lastLine){
            for(int i = stringInLineCount; i < maxWidth; i++ ){
                x += ' ';
            }
            return x;
        }else{
            int spaceBetween = spaceCount / (wordsInLineCount-1);
            int extraSpace = spaceCount % (wordsInLineCount-1);
            string tmp;
            int count = 0;
            int spaceNum = 0;
            for(int i = 0; i < maxWidth; i++) {
                
                if(spaceNum > 0){
                    tmp += ' ';
                    spaceNum--;
                    continue;
                }
                
                if(x[count] != ' '){
                    tmp += x[count];
                    count++;
                }else{
                    tmp += ' ';
                    spaceNum = spaceBetween-1;
                    if(extraSpace > 0) {spaceNum++; extraSpace--;}
                    count++;
                }
            }
            return tmp;
        }
    }
    
};
