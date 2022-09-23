57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
  
class Solution {
public:
    //Method 1: add new inteval to the end, sort the array, and perform the merge
    //Method 2: find the inserted position, and check prev and next intervals and make change, a bit complicated
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
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
