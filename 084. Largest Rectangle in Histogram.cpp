84. Largest Rectangle in Histogram (HARD)
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
  
  
class Solution {
public:
    /*Easy to find out O(n*n) method, but.. */
    /*Using stack to get O(n) result: Stack 消除直方图法*/
    //遍历所有高度，每次遇到新的高度，就把它包括进来：假如新的高度比前一个更高，无脑包含；如果新的高度比前一个高度低，则前一个高度此时没有意义了，从stack中把其扔了（同时iteration不变）。
    int largestRectangleArea(vector<int> &height) {
        vector<int> stack; /*Store index instead of height values*/
        height.push_back(0);/*!!!*/
        int result = 0;
        
        for(int i = 0; i < height.size(); i++){
            if(stack.empty() || height[stack.back()] < height[i]){
                stack.push_back(i);//如果当前元素大于栈顶元素，则入栈
            }else{//如果当前元素小于等于栈顶元素,合并现有栈（到result），直至栈顶元素小于当前元素
                int top = stack.back();/*!!!!!!!*/
                stack.pop_back();
                
                int length;
                if(stack.empty()) length = i;
                else length = i - stack.back() - 1;
                
                result = max(result, height[top] * length);
                i--;
            }
        }
        
        /*If input (1), height is (1,0)*/
        /*first loop i=0 stack push 0(value is 1)*/
        /*second loop i=1 stack pop 0(value is 1), result is 1, i reset to 0*/
        /*third loop i=1 stack push 1(value is 0)*/
        /*end*/
        
        /*If input (2,4), height is (2,4,0)*/
        /*first loop i=0 stack push 0(value is 2)*/
        /*second loop i=1 stack push 1(value is 4)*/
        /*third loop i=2 stack pop 1(value is 4), length is 2-0-1=1, result is 4*1=4, i reset to 1*/
        /*fourth loop i=2 stack pop 0(value is 2), length is 2, result is 2*2=4, i reset to 1*/
        /*fifth loop i=2 stack push 2(value is 0)*/
        /*end*/
        
        /*If input (2,3), height is (2,3,0)*/
        /*first loop i=0 stack push 0(value is 2)*/
        /*second loop i=1 stack push 1(value is 3)*/
        /*third loop i=2 stack pop 1(value is 3), length is 2-0-1=1, result is 3*1=3, i reset to 1*/
        /*fourth loop i=2 stack pop 0(value is 2), length is 2, result is 2*2=4, i reset to 1*/
        /*fifth loop i=2 stack push 2(value is 0)*/
        /*end*/
        
        /*If input (2,3,2), height is (2,3,2,0)*/
        /*first loop i=0 stack push 0(value is 2)*/
        /*second loop i=1 stack push 1(value is 3)*/
        /*third loop i=2 stack pop 1(value is 3), length is 2-0-1=1, result is 3*1=3, i reset to 1*/
        /*fourth loop i=2 stack pop 0(value is 2), length is 2, result is 2*2=4, i reset to 1*/
        /*fifth loop i=2 stack push 2(value is 2)*/
        /*sixth loop i=3 stack pop 2(value is 2), length is 3, result is 2*3=6, i reset to 2*/
        /*seventh loop i=3 stack push 3(value is 0)*/
        /*end*/
        
        /*If input (4,2,3), height is (4,2,3,0)*/
        /*first loop i=0 stack push 0(value is 4)*/
        /*second loop i=1 stack pop 0(value is 4), length is 1, result is 4*1=4, i reset to 0*/
        /*third loop i=1 stack push 1(value is 2)*/
        /*fourth loop i=2 stack push 2(value is 3)*/
        /*fifth loop i=3 stack pop 2(value is 3), length is 3-1-1=1, result is 3*1=3, i reset to 2*/
        /*sixth loop i=3 stack pop 1(value is 2), length is 3, result is 2*3=6, i reset to 2*/
        /*seventh loop i=3 stack push 3(value is 0)*/
        /*end*/
        
        /*If input (1,3,2), height is (1,3,2,0)*/
        /*first loop i=0 stack push 0(value is 1)*/
        /*second loop i=1 stack push 1(value is 3)*/
        /*third loop i=2 stack pop 1(value is 3), length is 2-0-1=1, result is 3*1=3, i reset to 1*/
        /*fourth loop i=2 stack push 2(value is 2)*/
        /*fifth loop i=3 stack pop 2(value is 2), length is 3-0-1=2, result is 2*2=4, i reset to 2*/
        /*sixth loop i=3 stack pop 0(value is 1), length is 3, result is 1*3=3, i reset to 2*/
        /*seventh loop i=3 stack push 3(value is 0)*/
        /*end*/
        
        return result;
    }
};
  
  
