1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

更新了三种Two Sum解法
1、先Sort，再双指针法：O(nlogn)
2、哈希表: 理论O(n)，但数据量不大则不明显
3、二重循环：最省内存，效率最低
考虑了输入数据有重复的情况。
 

class Solution {
public:
    /*Method1: Below is the 2 sum algorithm that is O(NlogN) + O(N). Runtime=12ms, Memory=10.5mb*/ 
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sortedNumbers;//create copy
        for(int i = 0; i < numbers.size(); i++) sortedNumbers.push_back(numbers[i]);
        
        sort(sortedNumbers.begin(), sortedNumbers.end()); //sort, O(NlogN)
        vector<int> returnNumbers = core(sortedNumbers, target);//O(N)
        
        vector<int> r;
        if(returnNumbers[0] == returnNumbers[1]){//!this code is to take into account of duplicate element in the input array
            for(int i = 0; i < numbers.size(); i++)//O(N)
                    if(numbers[i] == returnNumbers[0]) r.push_back(i);
        }else{ 
            for(int j = 0; j < returnNumbers.size(); j++)//2
                for(int i = 0; i < numbers.size(); i++)//O(N)
                    if(numbers[i] == returnNumbers[j]) r.push_back(i);
        }        
        
        if(r[0] > r[1]){
            r[0] = r[0]^r[1];
            r[1] = r[0]^r[1];
            r[0] = r[0]^r[1];
        }
 
        return r;
    }
    
    vector<int> core(vector<int> &sortedNumbers, int target) { //O(N)
        int len = sortedNumbers.size();
        vector<int> r;
        int i = 0; int j = len - 1;
        while(i < j){
            int x = sortedNumbers[i] + sortedNumbers[j];
            if(x == target){ 
                r.push_back(sortedNumbers[i]);
                r.push_back(sortedNumbers[j]);
                i++; j--;
            }else if(x > target) j--;
            else i++;
        }
        return r;
    }
    
    
    /*Method2: unordered_map, O(n). Runtime=27ms. Memory=12.1mb*/
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> r;
        
        bool found = false;
        for(int i = 0; i < nums.size(); i++) { 
            if(um.find(nums[i]) != um.end()){
                if(nums[i]*2 == target){//!this code is to take into account of duplicate element in the input array
                    r.push_back(um[nums[i]]);
                    r.push_back(i);
                    found=true;
                    break;
                }
            }else
                um.insert(make_pair(nums[i], i));
        }
        
        if(!found){
            for(int i = 0; i < nums.size(); i++) {
                if(target-nums[i] == nums[i]) continue; //!um should not have duplicate keys
                if(um.find(target-nums[i]) != um.end()){
                    r.push_back(um[target-nums[i]]);
                    r.push_back(i);
                    break;
                }
            }
        }
        
        if(r[0]>r[1]){
            r[0] = r[0]^r[1];
            r[1] = r[0]^r[1];
            r[0] = r[0]^r[1];
        }
        return r;
    }
 
    
    /*Method3: Exceed Time Limit*/
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        int index1 = 0;
        int index2 = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(j==i) continue;
                if(numbers[i] + numbers[j] == target){
                    index1 = i+1;
                    index2 = j+1;
                }
            }
        }
        
        if(index1>index2){
            index1 = index1^index2;
            index2 = index1^index2;
            index1 = index1^index2;
        }
        
        vector<int> r;
        r.push_back(index1);
        r.push_back(index2);
        return r;
    }
};

