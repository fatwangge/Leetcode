47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10


class Solution {
public:
    //Analyze: Need remove duplicate, it is not eazy to do that
    //example: [1,1,3]
    //first pick 1 => [[1]]            
    //second pick 1 => [[1,1],[1,1]] 
    //remove duplicate => [[1,1]] => loop every exisiting elems and compare the new added element, very time consuming
    //third pick 3 => [[1,1,3],[1,3,1][3,1,1]] 
    //Alternative Method: DFS => maintain a visited vector array
    //example: [1,1,3]
    //visited = {t,f,f}, oneRes = {1}
    //visited = {t,t,f}, oneRes = {1,1}
    //visited = {t,t,t}, oneRes = {1,1,3}, res.push_back(oneRes)
    //visited = {t,f,t}, oneRes = {1,3}
    //visited = {t,t,t}, oneRes = {1,3,1}, res.push_back(oneRes)
    //visited = {f,t,f}, continue
    //visited = {f,f,t}, oneRes = {3}
    //visited = {t,f,t}, oneRes = {3,1}
    //visited = {t,t,t}, oneRes = {3,1,1}, res.push_back(oneRes)
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);   
        vector<vector<int>> res;
        vector<int> oneRes;
        sort(nums.begin(), nums.end());
        DFSAlgorithm(nums, visited, 0, res, oneRes);
        return res;
    }
    
    void DFSAlgorithm(vector<int>& nums, vector<bool> &visited, int idx, vector<vector<int>> &res, vector<int> &oneRes){
        if(oneRes.size() == nums.size()){
            res.push_back(oneRes);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if(!visited[i]) {
                oneRes.push_back(nums[i]);
                visited[i] = true;
                DFSAlgorithm(nums, visited, i+1, res, oneRes);
                oneRes.pop_back();
                visited[i] = false;
            }
        }
    }
    
};
