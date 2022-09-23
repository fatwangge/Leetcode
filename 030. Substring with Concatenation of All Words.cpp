30. Substring with Concatenation of All Words (HARD)
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
There is no substring of length 16 is s that is equal to the concatenation of any permutation of words.
We return an empty array.
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
  
class Solution {
public:
    //建立一个words的map。同时对于每一个可能的s子串，建立一个s子串的map
    //外循环遍历s的所有子串，内循环遍历s子串里面每个word
    //这种寻找permutation组合的游戏，次序不重要，所以可以用map做
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> um_words;
        for(int i = 0; i < words.size(); i++) um_words[words[i]]++;
        int w = words[0].length();
        int h = words.size();
        
        vector<int> result;
        for(int i = 0; i < s.length() - w*h+1; i++){//!这里要加一
            unordered_map<string, int> um_s_substring;//范围从i ~ i+h*w
            bool bMatch = true;
            for(int j = 0; j < h; j++){//遍历um_s_substring的范围内的word，看看它们在不在um_words里
                string oneString = s.substr(i+j*w, w);
                if(um_words.find(oneString) == um_words.end()) {
                    bMatch = false;
                    break;
                }else{
                    um_s_substring[oneString]++;
                    if(um_s_substring[oneString] > um_words[oneString]) {
                        bMatch = false;
                        break;
                    }
                }
            }
            if(bMatch) result.push_back(i);
        }
        return result;
    }
};

