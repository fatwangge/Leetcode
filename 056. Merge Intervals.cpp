56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
  
class Solution {
public:
    //Analyze: First sort with start
    //push the first inteval to result, use this "current interval" to compare
    //for each interval, compare the current interval with the next interval
    //  if no overlap, push this interval to the result (as new current interval), then move to the next interval
    //  if there is overlap, update the current interval by merging the two intervals, and use it to compare with the next interval
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareFunc);
        vector<vector<int>> result{intervals[0]};
        for(int i = 1; i < intervals.size(); i++){
            vector<int> &currentInterval = result.back();
            if(currentInterval[1] < intervals[i][0]) result.push_back(intervals[i]);
            else currentInterval[1] = max(currentInterval[1], intervals[i][1]); 
        }
        return result;
    }
    static bool compareFunc(vector<int> x, vector<int> y){ return x[0] < y[0]; }
};
