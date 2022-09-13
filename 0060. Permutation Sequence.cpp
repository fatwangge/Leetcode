60. Permutation Sequence (HARD)
  
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 
Constraints:

1 <= n <= 9
1 <= k <= n!
  
class Solution {
public:
    //the next permutation is larger then the former number, except for the last one
    //Method 1: calculate every permutation, slow, 900ms
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 0; i < n; i++) nums.push_back(i+1);
        for(int i = 0; i < k-1; i++) nextPermutation(nums);
        
        string res;
        for(int i = 0; i < nums.size(); i++) res = res + (char)(nums[i]+'0');
        return res;
    }
    
    void nextPermutation(vector<int>& nums) { //the function code from 31. Next Permutation.cpp
        for(int i = nums.size()-1; i >= 1; i--){
            if(nums[i-1] < nums[i]){ //find the place of ascending
                int j = nums.size()-1;
                while(nums[i-1] >= nums[j]) j--;
                swap(nums[i-1], nums[j]);//swap nums[i-1] and another nums[j], which is smallest but also nums[i-1] < nums[j]
                sort(nums.begin()+i, nums.end());
                break;
            }
            if(i == 1) sort(nums.begin(), nums.end());
        }
    }
    
    //Method 2: go direct to the correct permutation, fast, 3ms
    string getPermutation(int n, int k) {
        string resultString;
        vector<int> input;
        for(int i = 0; i < n; i++) input.push_back(i+1);
 
        if(input.size() == 0) return resultString;
        
        k--;
        
        while(input.size() > 1){
            int f = factorization(input.size()-1);
            int pos = k/f;
            resultString += input[pos] + '0';
            input.erase(input.begin() + pos);

            k = k%f;
        }
        resultString += input[0] + '0';
        
        return resultString;
    }
    
    int factorization(int n){
        if(n == 0) return 1;
        int r = 1;
        for(int i = n; i > 0; i--) r *= i;
        return r;
    }
};
