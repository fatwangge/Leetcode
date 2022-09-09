49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
  
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string,int> um;   //first is sorted string, second is its idex in res
        for(int i = 0; i < strs.size(); i++){
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            if(um.find(sortedStr) != um.end()){
                res[um[sortedStr]].push_back(strs[i]);
            }else{
                res.push_back(vector<string>{strs[i]});
                um[sortedStr] = res.size()-1;
            }
        }
        
        return res;
    }
};
