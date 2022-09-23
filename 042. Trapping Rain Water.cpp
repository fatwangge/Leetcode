42. Trapping Rain Water (HARD)

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
  
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> lHighest(height.size(), 0), rHighest(height.size(), 0);
        lHighest[0] = height[0]; rHighest[height.size()-1] = height[height.size()-1];
        for(int i = 1; i < height.size(); i++)
            lHighest[i] = lHighest[i-1] > height[i] ? lHighest[i-1] : height[i];
        for(int i = height.size()-2; i >= 0; i--)
            rHighest[i] = rHighest[i+1] > height[i] ? rHighest[i+1] : height[i];
        for(int i = 1; i < height.size()-1; i++)
            if(min(lHighest[i], rHighest[i]) > height[i])
                res += min(lHighest[i], rHighest[i]) - height[i];
        return res;
    }
    
    //Wrong method: this assume the shape is a pyramid
    /*
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lastL = 0, lastR = 0, lastH = 0;
        int nextL = height[l], nextR = height[r];
        int res = 0;
        while(l <= r){
            if(nextL > lastL && nextR > lastR){
                res += (r-l+1) * (min(nextL, nextR) - lastH);
                lastL = nextL; lastR = nextR; 
                lastH = min(nextL, nextR);
            }           
            if(height[l] <= height[r]) nextL = max(nextL, height[++l]);
            else nextR = max(nextR, height[--r]);  
        }
        
        int mapArea = 0;
        for(int i = 0; i < height.size(); i++) mapArea += height[i];
        
        return res - mapArea;
    }*/
};
  
