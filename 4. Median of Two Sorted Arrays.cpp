4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
  
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
  
  
  class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Recursive binary search
        return GetMedian_TwoArrays(nums1, 0, nums1.size(), nums2, 0, nums2.size());
    }
    
    double GetMedian_TwoArrays(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2){
        double m1 = GetMedian_OneArray(nums1, start1, end1);
        double m2 = GetMedian_OneArray(nums2, start2, end2);
        int len1 = end1-start1;
        int len2 = end2-start2;
        int minLen = min(len1, len2);
        int r = minLen/2-1; //!the length to be thrown away
        if(r <= 0) r = 1;
        
        //Exit cases
        if(len1 == 0) return m2;
        if(len2 == 0) return m1;
        if(len1 == 1){
            vector<int> extendedNums2;
            InsertElem(nums2, start2, end2, extendedNums2, nums1[start1]);
            return GetMedian_OneArray(extendedNums2, 0, extendedNums2.size());
        }
        if(len2 == 1){
            vector<int> extendedNums1;
            InsertElem(nums1, start1, end1, extendedNums1, nums2[start2]);
            return GetMedian_OneArray(extendedNums1, 0, extendedNums1.size());
        }
        if(len1 == 2){
            vector<int> extendedNums2;
            InsertElem(nums2, start2, end2, extendedNums2, nums1[start1], nums1[start1+1]);
            return GetMedian_OneArray(extendedNums2, 0, extendedNums2.size());
        }
        if(len2 == 2){
            vector<int> extendedNums1;
            InsertElem(nums1, start1, end1, extendedNums1, nums2[start2], nums2[start2+1]);
            return GetMedian_OneArray(extendedNums1, 0, extendedNums1.size());
        }
 
        //Recursive
        if(m1 == m2) return m1;
        else if(m1 > m2) return GetMedian_TwoArrays(nums1, start1, end1-r, nums2, start2+r, end2);
        else return GetMedian_TwoArrays(nums1, start1+r, end1, nums2, start2, end2-r);
    }
    
    double GetMedian_OneArray(vector<int> nums, int start, int end){
        int len = end-start;
        
        //Exit cases
        if(len == 0) return 0; 
        if(len == 1) return nums[start];
        
        //Recrusive
        if(len%2 == 0) return (nums[start+len/2-1]+nums[start+len/2])/2.0f; //!
        else return nums[start+len/2];
    }

    void InsertElem(vector<int> &input, int start, int end, vector<int> &output, int elem){
            bool inserted = false;
            for(int i = start; i < end; i++) {
                if(elem <= input[i] && !inserted){
                    output.push_back(elem);
                    inserted = true;
                } 
                output.push_back(input[i]);
            }
            if(!inserted) output.push_back(elem);
    }
    void InsertElem(vector<int> &input, int start, int end, vector<int> &output, int elem1, int elem2){
            bool inserted1 = false;
            bool inserted2 = false;
            for(int i = start; i < end; i++) {
                if(elem1 <= input[i] && !inserted1){
                    output.push_back(elem1);
                    inserted1 = true;
                } 
                if(elem2 <= input[i] && !inserted2){
                    output.push_back(elem2);
                    inserted2 = true;
                } 
                output.push_back(input[i]);
            }
            if(!inserted1) output.push_back(elem1);
            if(!inserted2) output.push_back(elem2);
    }    
    
};
